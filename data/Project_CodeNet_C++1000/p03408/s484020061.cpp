#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int N, M;
	cin >> N;
	map<string, int> m;
	for(int i=0; i<N; ++i){
		string S;
		cin >> S;
		++m[S];
	}
	cin >> M;
	for(int i=0; i<M; ++i){
		string S;
		cin >> S;
		--m[S];
	}
	int ans = 0;
	for(const auto& value : m){
		ans = max(ans, value.second);
	}
	cout << ans << endl;
}