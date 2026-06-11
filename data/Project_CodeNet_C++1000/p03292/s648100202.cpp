#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ab = abs(a - b);
	int bc = abs(b - c);
	int ca = abs(a - c);
	cout << ab + bc + ca - max(ab, max(bc, ca)) << endl;
}