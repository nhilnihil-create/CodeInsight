#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	string S; cin >> S;
	int N = S.length();
	int cnt[3] = {};

	rep(i, N) {
		cnt[S[i] - 'a']++;
	}
	int K = 0;
	rep(i, 3) K += min(1, cnt[i]);
	int maxchar = max({ cnt[0], cnt[1], cnt[2] });
	int minchar = min({ cnt[0], cnt[1], cnt[2] });

	if (N == 1) {
		cout << "YES" << endl;
	}
	else if (N == 2) {
		if (K == 1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	else if (N > 2) {
		if (K == 3) {
			if (maxchar - minchar >= 2) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
		else if (K == 2) {
			cout << "NO" << endl;
		}
		else if (K == 1) {
			cout << "NO" << endl;
		}
	}

    return 0;
}
