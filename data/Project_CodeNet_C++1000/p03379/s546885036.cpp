#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int arr[60];
int n, p;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> orderedarr = arr;
	sort(orderedarr.rbegin(), orderedarr.rend());
	for (int i = 0; i < n; i++) {
		cout << (arr[i]
				< orderedarr[n / 2 - 1] ?
						orderedarr[n / 2 - 1] : orderedarr[n / 2]) << "\n";
	}
}
