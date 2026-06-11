#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using Graph=vector<vector<int>>;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
int roundup(int a,int b){return	(a-1)/b+1;}
void YN(bool flg){cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){cout<<(flg?"yes":"no")<<endl;}

signed main(){
	int h,w,n;cin>>h>>w>>n;
	vector<P> pos(n);
	rep(i,n) cin>>pos[i].first>>pos[i].second;
	sort(All(pos));
	int ans=h;
	P M=P(1,1);
	rep(i,n){
		if(pos[i].first-M.first+M.second>pos[i].second){
			ans=pos[i].first-1;
			break;
		}
		else if(pos[i].first!=M.first){
			M.second=min(M.second+pos[i].first-M.first,pos[i].second-1);
			M.first=pos[i].first;
		}
	}
	cout<<ans<<endl;
}
