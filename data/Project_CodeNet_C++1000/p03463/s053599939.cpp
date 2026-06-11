//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int n, a, b;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	if ((a & 1) == (b & 1))
		cout << "Alice" << endl;
	else
		cout << "Borys" << endl;
	return 0;
}
