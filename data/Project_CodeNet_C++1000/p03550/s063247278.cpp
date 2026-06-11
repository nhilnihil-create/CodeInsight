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
typedef pair<int,int> P;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
void YN(bool flg){cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){cout<<(flg?"yes":"no")<<endl;}
signed main(){
	int n,z,w;
	cin>>n>>z>>w;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	if(n==1) cout<<llabs(w-a[0])<<endl;
	else cout<<max(llabs(w-a[n-1]),llabs(a[n-1]-a[n-2]))<<endl;
}
