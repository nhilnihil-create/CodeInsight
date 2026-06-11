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

int gcd(int a, int b){
    if (b > a) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    
    while(T--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if (A < B || B > D) {
            cout << "No" << endl;
            continue;
        }
        //cout << gcd(B, D) << " " <<  (gcd(B, D) - A % gcd(B, D) % gcd(B, D)) + C - B << endl;
        if (((gcd(B, D) - A % gcd(B, D) % gcd(B, D)) + C - B) >= 0) 
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }


    return 0;
}
// A, A - B, A - B + D, A - 2B + D, A - 2B + 2D, A - 3B + 2D
// 9 7 5 9      No  (gcd(7, 9) = 1)
// 9 7 6 9      Yes 
// 14 10 7 12   No  (gcd(10, 12) = 2)
// 14 10 8 12   Yes
// 14 10 9 12   Yes
// 14 10 7 11   No  (gcd(10, 11) = 1)
// 14 10 8 11   No
// 14 10 9 11   Yes
// 9 10 5 10    No
// 10 10 5 10   Yes
// 11 10 5 10   Yes
// 16 10 5 10   No