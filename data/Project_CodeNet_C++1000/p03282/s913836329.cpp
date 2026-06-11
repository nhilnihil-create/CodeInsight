#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	string S;
	ll K;
	cin >> S >> K;

	if (K == 1){
		cout << S.at(0) << endl;
		return 0;
	}
	int cnt = 0;
	rep(i, (int)(S.size())){
		// cout <<"in" << endl;
		if (S.at(i) == '1') cnt++;
		else break ;
	}
	// cout << S <<endl;
	// cout <<"cnt: " << cnt << endl;
	if (cnt >= K) cout << 1 << endl;
	else if (cnt > 0) cout << S.at(cnt) << endl;
	else cout << S.at(0) << endl;
}


