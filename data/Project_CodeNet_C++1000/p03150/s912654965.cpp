#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
    int n = S.length();
    rep(i, n + 1) {
        
        rep(j, n + 1) {
            string T;
            if(i > j) continue;
            rep(k, n) {
                if(i <= k && k <= j) continue;
                T += S[k];
            }
            //cout << T << endl;
            if(T == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
