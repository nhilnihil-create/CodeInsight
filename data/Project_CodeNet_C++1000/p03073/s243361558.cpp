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
    int ans0 = 0, ans1 = 0;
    rep(i, n) {
        if(i % 2 == 0 && S[i] == '0') ans0++;
        else if(i % 2 == 1 && S[i] == '1') ans0++;
        else if(i % 2 == 0 && S[i] == '1') ans1++;
        else if(i % 2 == 1 && S[i] == '0') ans1++;
    }
    cout << min(ans0, ans1) << endl;

    return 0;
}
