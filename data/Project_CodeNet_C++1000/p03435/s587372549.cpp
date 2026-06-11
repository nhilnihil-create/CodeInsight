#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int arr[4][4];
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	if (arr[1][1] - arr[1][2] == arr[2][1] - arr[2][2]
			&& arr[3][1] - arr[3][2] == arr[2][1] - arr[2][2]
			&& arr[1][1] - arr[1][3] == arr[2][1] - arr[2][3]
			&& arr[3][1] - arr[3][3] == arr[2][1] - arr[2][3]
			&& arr[1][2] - arr[1][3] == arr[2][2] - arr[2][3]
			&& arr[3][2] - arr[3][3] == arr[2][2] - arr[2][3]) {
		cout << "Yes\n";
	} else
		cout << "No\n";
}
