#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int t[n], x[n], y[n];
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> x[i] >> y[i];
	}

	bool ok = true;
	int pret = 0, prex = 0, prey = 0;
	for (int i = 0; i < n; i++)
	{
		int dt = abs(t[i] - pret), dx = abs(x[i] - prex), dy = abs(y[i] - prey);
		if(dt < dx + dy || dt % 2 != (dx + dy) % 2) {
			ok = false;
			break;
		}
		pret = t[i], prex = x[i], prey = y[i];
	}

	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
