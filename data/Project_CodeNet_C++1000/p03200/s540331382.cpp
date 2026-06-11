#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int main(int argc, char *argv[]) {

	string S; cin >> S;

	int stone_cnt = 0;
	long ans = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'B') {
			stone_cnt++;	
		}
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'B') {
			ans += S.size() - stone_cnt + 1 - i-1;
			stone_cnt--;
		}
	}
	cout << ans << endl;
	
	return 0;
}
