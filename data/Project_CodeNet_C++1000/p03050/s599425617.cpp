#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> div;
	long long ans = 0;
	for(int i = 1; i <= sqrt(n); i++) {
		if(n%i == 0) div.push_back(i);
	}
	long long tam = div.size();
	for(int i = 0; i < tam; i++) if(div[i] != sqrt(n)) div.push_back(n / div[i]);
	tam = div.size();
	for(int i = 0; i < tam; i++) div[i] -= 1;
	for(int i = 0; i < tam; i++) {
		if(div[i] >= sqrt(n)) ans += div[i];
	}
	cout << ans;
	return 0;
}