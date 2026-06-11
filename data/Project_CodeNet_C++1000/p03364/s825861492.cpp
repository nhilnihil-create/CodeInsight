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
	int n;cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];
	int ans=0;
	int tmp=0;
	rep(A,n){
		bool ok=true;
		rep(i,n) rep(j,n){
			int nex=(i+A)%n,ney=j;
			int tx=(j+A)%n,ty=i;
			if(s[nex][ney]!=s[tx][ty]){ 
				ok=false;
			}
		}
		if(ok) ans+=n-A;
	}
	rep(B,1,n){
		bool ok=true;
		rep(i,n) rep(j,n){
			int nex=i,ney=(j+B)%n;
			int tx=j,ty=(i+B)%n;
			if(s[nex][ney]!=s[tx][ty]){ 
				ok=false;
			}
		}
		if(ok) ans+=n-B;
	}
	cout<<ans<<endl;
}