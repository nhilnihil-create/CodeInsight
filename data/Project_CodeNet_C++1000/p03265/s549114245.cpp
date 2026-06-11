#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;

int a, b, c, d,X,Y;

int main() {
	cin >> a >> b >> c >> d;
	
	X = (a - c), Y = (d - b);

	cout << c -Y << " " << d-X << " " << a - Y<< " " << b-X << endl;
}