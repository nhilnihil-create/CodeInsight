#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string S;
	cin >> S;

	int ans = S.size();
	rep(i, 2){
		int cnt = 0;
		rep(j, (int)(S.size())){
			// if (j % 2 == 0 && S.at(j) == i + '0') //even
			// if (j % 2 != 0 && S.at(j) != i + '0') //odd
			if ((j % 2) ^ (S.at(j) == i + '0')) cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}