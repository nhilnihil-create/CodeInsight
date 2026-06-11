#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
const ll INF=1e15;
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
 
long long binpows(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  //impar
            res = res * a;
        a = a * a;
        b >>= 1;  // /2
    }
    return res;
}
const int mod=1e9+7;
int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
//CHECAR SE PRECISA DE LONG LONG
int n;
vector<int> v;
int dp[401][401];
int pre[402];
int resolve(int l, int r){
	if(l==r){
		return 0;
	}
	int &x=dp[l][r];
	if(x!=-1)
		return x;
	x=INF;
	for(int i=l; i<r; i++){
		x=min(x,resolve(l,i)+resolve(i+1,r) + pre[r+1]-pre[l]);
	}
	return x;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	pre[0]=0;
	cin>>n;
	v.resize(n);
	for(auto &i: v)
		cin>>i;
	for(int i=1; i<=n; i++){
		pre[i]=v[i-1];
		pre[i]+=pre[i-1];
	}
	cout<<resolve(0,n-1)<<endl;
}
//revise as variaveis e a ordem nas funções
signed main(){fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}