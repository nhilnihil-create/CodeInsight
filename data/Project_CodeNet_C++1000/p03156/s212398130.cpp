#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main(){
	int c, b, n, res = 0;
	cin >> n >> c >> b;
	int A = 0, AB = 0, B = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] <= c) A++;
		else if (c + 1 <= a[i] && a[i] <= b) AB++;
		else B++;
	}
	
	cout << min(A, min(AB, B));
	return 0;
}