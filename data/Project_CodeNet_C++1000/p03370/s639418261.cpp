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
	int N, X;
	cin >> N >> X;
	vector<int> m(N);
	int sum = 0;
	for(int i=0; i<N; ++i){
		cin >> m[i];
		sum += m[i];
	}
	sort(m.begin(), m.end());
	cout << N + (X-sum)/m[0] << endl;
}