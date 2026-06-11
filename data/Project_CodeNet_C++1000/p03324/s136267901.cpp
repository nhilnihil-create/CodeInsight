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
	ll d,n;
	cin >> d >> n;
	if(d==0){
		if(n<=99) cout << n << endl;
		else cout << 101 << endl;
	}else if(d==1){
		if(n<=99) cout << 100*n << endl;
		else cout << 10100 << endl;
	}else{
		if(n<=99) cout << 10000*n << endl;
		else cout << 1010000 << endl;
	}
	return 0;
}