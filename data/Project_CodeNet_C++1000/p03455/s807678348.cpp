#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a % 2 == 0 || b % 2 == 0) {
		cout << "Even" << endl;
	}
	else {
		cout << "Odd" << endl;
	}
}