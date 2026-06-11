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
bool prime[100010];

void set_prime() {
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i < 1000; i++) {
		int j = 2;
		while (i * j <= 100000) {
			prime[i*j] = 1;
			j++;
		}
	}
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    set_prime();
    vector<int> v;
    REP(i, 2, 55555) {
        if (prime[i] == 0 && i % 5 == 1) v.push_back(i);
    }
    int N; cin >> N;
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << v[i];
    }
    cout << endl;


    return 0;
}
// 7+7+7+7+7