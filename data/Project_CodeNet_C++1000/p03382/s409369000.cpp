#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const ll MAX_N = 1e5 + 5;
ll n, tmp, val;
ll Arr[MAX_N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Arr[i];

	sort(Arr, Arr + n);
	tmp = 0, val = -1;
	for (int i = 0; i + 1 < n; i++)
		if (val < min(Arr[i], Arr[n - 1] - Arr[i])) {
			val = min(Arr[i], Arr[n - 1] - Arr[i]);
			tmp = Arr[i];
		}

	cout << Arr[n - 1] << " " << tmp << "\n";
	return 0;
}