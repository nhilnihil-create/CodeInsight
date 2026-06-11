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

ll f(ll A) {
    if(A % 4 == 0) return A;
    if(A % 4 == 1) return 1;
    if(A % 4 == 2) return A + 1;
    return 0;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    cout << (f(B) ^ f(A - 1)) << endl; 

    return 0;
}
// 0000 ^ 1100 = 1100
// 1100 ^ 1101 = 0001
// 0001 ^ 1110 = 1111
// 1111 ^ 1111 = 