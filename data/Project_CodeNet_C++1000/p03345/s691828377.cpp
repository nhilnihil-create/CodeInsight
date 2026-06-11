#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
	ll a,b,c,k;cin>>a>>b>>c>>k;
	if (k % 2 == 1){
		if (abs(b - a) <= pow(10,18)){
			cout << b - a << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	else{
		if (abs(a - b) <= pow(10,18)){
			cout << a - b << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	return 0;
}

