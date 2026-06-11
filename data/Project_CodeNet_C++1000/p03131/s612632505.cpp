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
int main(){
	cout << fixed << setprecision(10);
	ll k,a,b;
	cin >> k >> a >> b;
	if(a+2>=b) cout << 1+k << endl;
	else{
		//cout << "Yes" << endl;
		ll n = a - 1;
		//cout << (b-a)*(k-n)/2 << " " << n%2 << endl;
		cout << (b-a)*((k-n)/2) + (k-n)%2 + a << endl;
	}
	return 0;
}