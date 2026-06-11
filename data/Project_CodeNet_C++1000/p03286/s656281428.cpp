#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 n;
void solve(){
	cin >> n;
	
	string s;
	int i = 0;
	while(n){
		if(n>>i&1){
			s = '1'+s;
			n += (1LL<<i)*(-1+2*(i&1));
		}
		else{
			s = '0'+s;
		}
		i++;
	}
	if(s.size()==0) cout << 0 << endl;
	else cout << s << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}