#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n;
bool prime(int a){
	for(int i = 2; i*i <= a; i++){
		if(a % i == 0) return 0;
	}
	return 1;
}
void solve(){
	cin >> n;
	vector<int> v;
	for(int i = 2; i < 55555; i++){
		if(prime(i)){
			if(i % 5 == 1) v.push_back(i);
		}
	}
	
	while(n--){
		cout << v[n] << " ";
	}
	cout << endl;
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
