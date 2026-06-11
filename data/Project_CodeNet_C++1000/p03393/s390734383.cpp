#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



string s;
void solve(){
	cin >> s;
	int n = s.size();
	if(n == 26){
		for(int i = n-1; i > 0; i--){
			if(s[i] > s[i-1]){
				for(int j = 0; j < i-1; j++){
					cout << s[j];
				}
				char c = 'z';
				for(int j = i; j < n; j++){
					if(s[j] > s[i-1]) c = min(c, s[j]);
				}
				cout << c << endl;
				return;
			}
		}
		cout << -1 << endl;
		return;
	}
	else{
		bool use[26] = {};
		for(int i = 0; i < n; i++){
			use[s[i]-'a'] = 1;
		}
		for(int i = 0; i < 26; i++){
			if(!use[i]){
				s += (char)('a'+i);
				cout << s << endl;
				return;
			}
		}
	}
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
