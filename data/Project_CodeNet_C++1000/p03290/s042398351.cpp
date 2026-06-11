#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (ll)(1ll<<60)
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll d,g;//d 点数の種類 g 目標展
	cin>>d>>g;
	vector<ll> p(d),c(d);//p 同じ得点の問題の数 c ボーナス
	rep(i,d)  cin>>p[i]>>c[i];

	ll ans=INF;
	ll score,num;

	rep(i,(1<<d)){//全部解く問題について、bit全探索
		score=0;num=0;

		vector<bool> selected(d,false);//jを全部解くならselected[j]=true
		rep(j,d){
			if((i>>j)&1){//jの問題は全部解く
				score+=(p[j]*100*(j+1)+c[j]);
				num+=p[j];
				selected[j]=true;
			}
		}

		for(int j=d-1;j>=0;j--){//全部解く問題を選び終わったら、後は、点数の高い順に貪欲に問題を解く(ただし、1問は残さなければならない<-全部解くのは許されない)
			if(selected[j]) continue;

			for(int k=0;k<p[j]-1;k++){
				if(score>=g) break;
				
				score+=(100*(j+1));
				num++;
			}
			if(score>=g) break;
		}

		if(score>=g) ans=min(ans,num);//scoreがg以上で達成されていればminをとる
	}

	cout<<ans<<endl;
	return 0;
}