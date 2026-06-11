#include <bits/stdc++.h>

using namespace std;
const int N = 110;
int _w;

int n, a[N];
vector<int> ans;

int main() {
	cin >> n;
	for( int i = 1; i <= n; ++i )
		cin >> a[i];
	while(n) {
		bool flag = false;
		for( int i = n; i >= 1; --i )
			if( a[i] == i ) {
				ans.push_back(i);
				for( int j = i; j < n; ++j )
					a[j] = a[j+1];
				--n;
				flag = true;
				break;
			}
		if( flag == false ) {
			puts("-1");
			return 0;
		}
	}
	for( auto it = ans.rbegin(); it != ans.rend(); ++it )
		printf( "%d\n", *it );
	return 0;
}
