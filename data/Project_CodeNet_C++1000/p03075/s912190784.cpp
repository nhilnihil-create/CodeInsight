#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>a(5);
	for (int i = 0; i < 5; i++)cin >> a.at(i);
	int k; cin >> k;
	if (a.at(4) - a.at(0) > k)cout << ":(" << endl;
	else cout << "Yay!" << endl;
}