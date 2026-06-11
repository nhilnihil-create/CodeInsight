#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	char x, y;
	cin >> x >> y;
	if (x < y) cout << "<" << endl;
	else if (x == y) cout << "=" << endl;
	else cout << ">" << endl;
}