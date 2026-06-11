#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define pi acos(-1)
#define mod 1000000007


using namespace std;


int main() {
	HS;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int diffX = x2 - x1, diffY = y2 - y1;
	int x3, y3, x4, y4;
	x3 = x2 - diffY;
	y3 = y2 + diffX;
	x4 = x1 - diffY;
	y4 = y1 + diffX;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


	return 0;
}