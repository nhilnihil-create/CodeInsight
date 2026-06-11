#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int prime[101000];
bool is_prime[101000];
void sieve(int n){
	// n以下の素数を求める
	int p = 0;
	for(int i=0;i<=n;i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <=n ; i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j <=n;j+=i) is_prime[j] = false;
		}
	}
}
int main(){
	cout << fixed << setprecision(10);
	sieve(100010);
	vector<int> sum(100011,0);
	rep(i,100010){
		if( i%2!=0 && is_prime[i] && is_prime[(i+1)/2]){
			sum[i+1] = sum[i] + 1;
		}else sum[i+1] = sum[i]; 
	}
	int q;
	cin >> q;
	rep(i,q){
		int l,r;
		cin >> l >> r;
		cout << sum[r+1] - sum[l] << endl; 
	}
	return 0;
}