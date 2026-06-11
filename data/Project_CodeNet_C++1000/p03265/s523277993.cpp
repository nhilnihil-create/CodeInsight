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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int diffx = x1 - x2;
	int diffy = y1 - y2;
	cout << x2 + diffy << " " << y2 - diffx << " " << x1 + diffy << " " << y1 - diffx;
}