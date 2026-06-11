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



string s;
int k;
set<string> st;
void solve(){
	cin >> s;
	cin >> k;
	int n = s.size();
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j+i <= n && j <= k; j++){
			st.insert(s.substr(i,j));
		}
	}
	auto ans = st.begin();
	for(int i = 1; i < k; i++){
		ans++;
	}
	cout << *ans << endl;
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