#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


// Write From This Line
int main()
{
	long long x, y;
	cin >> x >> y;
	// yがxの約数だったら存在しない
	if(x % y == 0) puts("-1");
	else {
		while(1){
			if(x % y != 0){
				cout << x << endl;
				return 0;
			} else {
				 x += x;
			}
		}
	}
}
