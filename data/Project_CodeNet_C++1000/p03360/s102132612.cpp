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
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	cout << A + B + C - max(A, max(B, C)) + max(A, max(B, C)) * pow(2, K) << endl;
}