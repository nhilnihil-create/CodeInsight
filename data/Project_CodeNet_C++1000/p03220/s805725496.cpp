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

int ctoi(const char c){
	if('0' <= c && c <= '9') return (c-'0');
	return -1;
}

int main(){
	int N, T, A;
	cin >> N >> T >> A;
	vector<double> H(N);
	for(int i=0; i<N; ++i) cin >> H[i];
	int ans = 0;
	double best = intMAX;
	for(int i=0; i<N; ++i){
		double temp = T - H[i] * 0.006;
		if(abs(best - A) > abs(temp - A)){
			best = temp;
			ans = i+1;
		}
	}
	cout << ans << endl;
}