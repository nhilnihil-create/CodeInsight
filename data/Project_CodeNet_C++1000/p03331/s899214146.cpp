#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;

int main() {
	int n;
	cin >> n;
	
	if(n % 10 != 0) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		cout << sum << endl;
	}
	else cout << 10 << endl;
}