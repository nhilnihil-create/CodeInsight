#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, h, w;
	cin >> n >> h >> w;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		//cout << a[i] << ' ' << b[i] << "\n";
	}

	int counter = 0;

	for(int i = 0; i < n; ++i){
		if(h <= a[i] && w <= b[i]) ++counter;
		else continue;
	}

	cout << counter << "\n";

	return 0;
	
}