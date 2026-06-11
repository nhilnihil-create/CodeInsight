#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 3 << endl;
		return 0;
	}
	int m = n * (n - 1) / 2;
	if (n % 2 == 1) {
      m-=n/2;
		cout << m << endl;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
              if(i+j==n) continue;
              cout<<i<<" "<<j<<endl;
			}
		}
	}
	else {
		m -= n / 2;
		cout << m << endl;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i + j == n+1) continue;
				cout << i << " " << j << endl;
			}
		}
	}
}