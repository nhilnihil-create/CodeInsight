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
	string S;
	cin >> S;
	int ans = intMAX;
	for(int i=0; i<S.length()-2; ++i){
		int num = 0;
		num += ctoi(S[i]) * 100;
		num += ctoi(S[i+1]) * 10;
		num += ctoi(S[i+2]);
		ans = min(ans, abs(753-num));
	}
	cout << ans << endl;
}