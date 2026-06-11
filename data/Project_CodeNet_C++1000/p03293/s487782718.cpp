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
	string S, T;
	cin >> S >> T;
	string ans = "No";
	for(int i=0; i<S.length(); ++i){
		S = S[S.length()-1] + S;
		S.erase(S.length()-1);
		if(S==T) ans = "Yes";
	}
	cout << ans << endl;
}