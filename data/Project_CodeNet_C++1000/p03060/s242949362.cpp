#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define iter std::vector<int>::iterator

int main() {
	ios_base ::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> value(n+1), cost(n+1);

	for (int i=1; i<=n; i++) {
		cin >> value[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> cost[i];
	}


	int res = 0; 
	for (int i = 1; i <= n; i++) {
		if (value[i] - cost[i] > 0) {
			res += value[i]-cost[i];
		}
	}
	
	cout << res;



	return 0;	
}