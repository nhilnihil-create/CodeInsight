#include <bits/stdc++.h>
// #define int long long
#define Matrix vector<vector<int> >
// #define Matrix vector<vector<int> >
#define double long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define td(v) v.begin(),v.end()
#define tdr(v) v.rbegin(),v.rend()
#define endl "\n"
#define Matrix vector<vector<int> >
using namespace std;
const int MOD = 1e9+7;
const long long INF = 5e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
 
inline long long mod(long long n, long long m){
    long long ret = n%m;
    if(ret < 0) ret += m;
    return ret;
}
 
double rad(double x){
    return x*pi/180.0;
}
 
bool isleft(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int det = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
    if(det>=0) return true;
    if(det<0) return false;
    return false;
}
 
int exp(int a, int b){
    int result = 1;
    while (b > 0){
        if (b & 1)
            result = mod(result*a,MOD);
 
        b >>= 1;
        a = mod(a*a,MOD);
    }
    return result;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<bool> ans(k+1,false);
	vector<int>v(n);
	for(int &i : v){
		cin>>i;
	}
	for(int i=1;i<=k;i++){
		bool ok=false;
		for(int &j : v){
			if(i-j<0) continue;
			if(!ans[i-j]){
				ok=true;
			}
		}
		ans[i]=ok;
	}
	cout<<(ans[k] ? "First" : "Second")<<endl;
}

signed main(){
    fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
}