#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string N;
	cin >> N;

	if (N.size() == 1){
		cout << N << endl;
		return 0;
	}
	int ans = N.at(0) - 1 - '0' + 9 * (N.size() - 1);
	rep2(i, (int)(N.size()), 1, 1){
		if (N.at(i) != '9'){
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans + 1 << endl;
}