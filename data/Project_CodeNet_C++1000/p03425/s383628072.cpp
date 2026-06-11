
// C - March

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll cnt[5];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		string S;
		cin >> S;
		switch(S[0]) {
			case 'M':
				cnt[0]++;
				break;
			case 'A':
				cnt[1]++;
				break;
			case 'R':
				cnt[2]++;
				break;
			case 'C':
				cnt[3]++;
				break;
			case 'H':
				cnt[4]++;
				break;
		}
	}

	ll ans = 0;

	for (int i=0; i<5; i++) {
		for (int j=i+1; j<5; j++) {
			for (int k=j+1; k<5; k++) {
				ans += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}

	cout << ans << endl;

	return 0;
}