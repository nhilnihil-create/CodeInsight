#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1);
//or-> ||
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	int H,W;
	cin>>H>>W;
	char s;
	int ans[H+2][W+2]={0};
	rep(i,1,H+1){
		rep(j,1,W+1){
			cin>>s;
			if(s=='#') ans[i][j]=1;
		}
	}
	rep(i,1,H+1){
		rep(j,1,W+1){
			if(ans[i][j]){
				if(ans[i-1][j]) continue;
				if(ans[i+1][j]) continue;
				if(ans[i][j-1]) continue;
				if(ans[i][j+1]) continue;
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
