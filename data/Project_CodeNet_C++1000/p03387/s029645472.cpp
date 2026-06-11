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
    int A[3];
    rep(i, 3) cin >> A[i];
    int ans = 0;
    sort(A, A + 3);
    while(A[0] != A[2]) {
        if(A[2] - A[0] >= 2) A[0] += 2;
        else {A[0]++; A[1]++;}
        sort(A, A + 3);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
