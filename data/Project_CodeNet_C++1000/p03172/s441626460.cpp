#include <bits/stdc++.h>
#define int long long
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
	vector<int>v(n);
	for(int &i : v)
		cin>>i;
	vector<int>vet(1e5+1,0);
	for(int i=0;i<=v[0];i++){
		vet[i]=1;
	}
	vector<int>prefix;
	prefix.push_back(vet[0]);
	for(int i=1;i<=1e5; i++){
		int x = prefix.back();
		prefix.push_back(vet[i]+x);
	}
	for(int i=1;i<n;i++){
		vector<int>newvet(1e5+1,0);
		for(int j=0;j<=k;j++){
			int bot = max(0ll, j-v[i-1]);
			int top = min(j,v[i]);
			if(bot>top) continue;
			newvet[j]=prefix[j-bot]-prefix[j-top]+vet[j-top];
			newvet[j]=mod(newvet[j],MOD);
		}
		vet = newvet;
		prefix.clear();
		prefix.push_back(vet[0]);
		for(int j=1;j<=1e5; j++){
			if(vet[j]>0) v[i]=j;
			int x = prefix.back();
			prefix.push_back(vet[j]+x);
			prefix[j]%=MOD;
		}
	}
	cout<<vet[k]<<endl;
}

signed main(){
    fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
}