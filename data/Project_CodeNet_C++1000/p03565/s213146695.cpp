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
    string S, T;
    cin >> S >> T;
    string A = "NOTHING";
    rep(i, S.length()) {
        string R = "";
        bool ok = true;
        int cnt = 0;
        rep(j, S.length()) {
            if(j < i || cnt == T.length()) {
                if(S[j] == '?') R += 'a';
                else R += S[j];
            } else if (S[j] != '?' && S[j] != T[cnt]) {
                ok = false;
                break;
            } else {
                R += T[cnt++];
            }
        }
        //cout << i << " " << R << " " << ok << " " << cnt << endl;
        if(ok && cnt == T.length()){
            if(A == "NOTHING" || A > R) A = R;
        }
    }
    if(A == "NOTHING") {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << A << endl;
    }

    return 0;
}
