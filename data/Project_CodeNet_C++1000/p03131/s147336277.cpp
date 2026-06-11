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
    ll K, A, B;
    cin >> K >> A >> B;
    ll ans = 1;
    
    ll C = B - A;
    int cnt = max(0LL, min(K, A - ans));
    ans += cnt;
    K -= cnt;
    if (K % 2 == 1) {ans++; K--;}
    if(C >= 2) ans += C * K / 2;
    else ans += K;
    cout << ans << endl;
    return 0;
}
