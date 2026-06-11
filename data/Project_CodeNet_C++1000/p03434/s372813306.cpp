#include<bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[10000];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, std::greater<int>());
	int ascore=0;
	int bscore=0;
	for (int i=0; i<n; i++) {
		if (i%2==0) {
			ascore+=a[i];
		} else bscore+=a[i];
	}
	cout << ascore-bscore;
} 