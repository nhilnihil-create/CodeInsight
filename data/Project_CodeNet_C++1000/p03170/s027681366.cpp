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
bool dp[123456];
void solve(){
	int n,k;
	cin>>k>>n;
	vector<int> v(k);
	for(auto &i: v)
		cin>>i;
	sort(v.begin(),v.end());

	for(int i=1; i<=n; i++){
		for(int j=0; j<v.size(); j++){
			if(v[j]>i)
				break;
			if(dp[i-v[j]]==0){
				dp[i]=1;
				break;
			}
		}
	}
	if(dp[n]==1){
		cout<<"First"<<endl;
	}else{
		cout<<"Second"<<endl;
	}
}
//revise as variaveis e a ordem nas funções
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}