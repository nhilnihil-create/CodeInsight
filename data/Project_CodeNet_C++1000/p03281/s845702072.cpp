#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	if(n<105){
		cout<<0;
		return 0;
	}
	int ans=0;
	rep(i,105,n+1){
		if(i%2==0)continue;
		int k=i;
		int cnt=1;
		for(int j=2;j*j<=i;j++){
			if(k%j==0){
				int a=0;
				while(k%j==0){
					a++;
					k/=j;
				}
				cnt*=(a+1);
			}
		}
		if(cnt==8)ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}