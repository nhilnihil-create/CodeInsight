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
#define int long long
int gcd(int a, int b) {
	//cout << a << " " << b << endl;
	if (b > a) return gcd(b, a);
	else if (b == 0) return a;
	else return gcd(b, a % b);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int T; cin >> T;
	rep(i, T) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		if (B > A) {
			cout << "No" << endl;
		}
		else if (B > D) {
			cout << "No" << endl;
		}
		else if (C >= B) {
			cout << "Yes" << endl;
		}
		else {
			int g = gcd(B, D);
			//cout << g << endl;
			int X = B - g + A % g;
			if (X > C) {
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
		}


	}
 
    return 0;
}
