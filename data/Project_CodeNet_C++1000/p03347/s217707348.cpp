#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
int roundup(int a,int b){return	(a-1)/b+1;}

signed main(){
	int n;cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	if(a[0]!=0){
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	rep(i,n-1){
		if(a[i+1]==a[i]+1) ans++;
		else if(a[i+1]<=a[i]){
			ans+=a[i+1];
		}
		else{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}
