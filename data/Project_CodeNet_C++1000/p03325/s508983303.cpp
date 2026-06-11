#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while(x % 2 == 0) {
			x /= 2;
			cnt++;
		}
	}
	cout << cnt;
}
