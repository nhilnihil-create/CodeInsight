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
    int N; cin >> N;
    int ok = N;
    int ng = 0;
    
    cout << 0 << endl;
    string S; cin >> S;
    if(S == "Vacant") return 0;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        cout << mid << endl;
        string T; cin >> T;
        if(T == "Vacant") return 0;
        if(mid % 2 == 0 && S == T) ng = mid;
        else if(mid % 2 == 0 && S != T) ok = mid;
        else if(mid % 2 == 1 && S != T) ng = mid;
        else ok = mid;
    }

    return 0;
}
