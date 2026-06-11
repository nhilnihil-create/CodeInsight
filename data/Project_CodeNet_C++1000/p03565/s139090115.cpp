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
    string K;
    //if(S.length() < T.length()) {cout << "UNRESTORABLE" << endl; return 0;}
    rep(i, S.length()) {
        bool ok = true;
        string U;
        rep(j, i) {
            if(S[j] == '?') U += 'a'; 
            else U += S[j];
        }
        rep(j, T.length()) {
            if(i + j >= S.length()) {ok = false; break;}
            if(S[i + j] != T[j] && S[i + j] != '?') ok = false;
            U += T[j];
        }
        REP(j, i + T.length(), S.length() - 1) {
            if(S[j] == '?') U += 'a'; 
            else U += S[j];
        }
        if(ok) {
            if(K == "") K = U;
            else if(K > U) K = U;
        } 
    }
    if(K == "") {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << K << endl;
    }

    return 0;
}
