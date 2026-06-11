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
	int ans = 0;
	int N;
	cin >> N;
	for(int i=1; i<32; ++i){
		for(int j=2; j<10; ++j){
			if(pow(i, j) <= N){
				ans = max(ans, (int)pow(i, j));
			}else break;
		}
	}
	cout << ans << endl;
}