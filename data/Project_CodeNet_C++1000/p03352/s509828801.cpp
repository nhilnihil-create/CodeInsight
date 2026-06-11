#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int X;
	cin >> X;

	int ans = 1;
	rep2(i, 32, 2, 1){ //b
		if (i >= X) break ;
		int tmp = i;
		while(tmp * i <= X){ //p
			tmp *= i;
		}
		if (tmp == i) tmp = 0;
		ans = max(ans, tmp);
		// cout << i << ": " << tmp << endl;
	}
	cout << ans << endl;
}