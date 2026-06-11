#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, sum = 0;
	cin >> a >> b;
    int k[100000];
	vector<int>dis;
	for (int i = 0; i < b; ++i) { cin >> k[i]; }
	sort(k, k + b);
	if (a >= b) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < b; ++i) {
		dis.push_back(abs(k[i] - k[i - 1]));
		sum += abs(k[i] - k[i - 1]);
	}
	sort(dis.rbegin(), dis.rend());
	for (int i = 0; i < a - 1; ++i) {
		sum -= dis[i];
	}
	cout << sum << endl;
}