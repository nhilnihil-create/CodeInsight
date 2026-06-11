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



int n, Q;
string s;
void solve(){
	cin >> n;
	cin >> s;
	cin >> Q;
	
	for(int t = 0; t < Q; t++){
		int k = 0;
		cin >> k;
		i64 a=0,b=0,c=0;
		i64 cnt = 0;
		for(int i = 0; i < n; i++){
			if(i >= k){
				if(s[i-k] == 'D'){
					c-=b;
					a--;
				}
				if(s[i-k] == 'M') b--;
			}
			if(s[i] == 'D') a++;
			if(s[i] == 'M'){ b++; c+=a; }
			if(s[i] == 'C') cnt += c;
		}
		cout << cnt << endl;
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
