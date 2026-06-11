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
//LEMBRAR DE DAR FLUSH

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	int dp[123456];
	int pre[123456];
	for(int i=0; i<=k; i++){
		dp[i]=0;
		pre[i]=1;
	}
	dp[0]=1;
	for(int i=0; i<n; i++){
		for(int j=k; j>=1; j--){
			int aux=pre[j-1]-(j-v[i]-1<0?0:pre[(j-v[i]-1)]);
			if(aux<0)
				aux+=mod;
			dp[j]+=aux;
			dp[j]%=mod;
		}
		for(int j=0; j<=k; j++){
			pre[j]=dp[j];
			if(j!=0)
				pre[j]+=pre[j-1];
		}
	}
	cout<<dp[k]<<endl;
}
//revise as variaveis e a ordem nas funções
signed main(){fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}