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
int N, Q;
string S;
char t[200010], d[200010];

int binary_searchL() {
    int ok = -1;
    int ng = N;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        bool ok1 = true;
        int x = mid;
        rep(i, Q) {
            if(x < 0) continue;
            if(S[x] == t[i]) {
                if(d[i] == 'L') x--;
                else x++;
            }
            if(x >= N) {
                ok1 = false;
                break;
            }
        }
        if(ok1) ok = mid;
        else ng = mid;
        //cout << mid << " " << ok << " " << ng << " " << ok << endl;
    }
    return ok;
}

int binary_searchR() {
    int ok = N;
    int ng = -1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        bool ok1 = true;
        int x = mid;
        rep(i, Q) {
            if(x >= N) continue;
            if(S[x] == t[i]) {
                if(d[i] == 'L') x--;
                else x++;
            }
            if(x < 0) {
                ok1 = false;
                break;
            }
        }
        if(ok1) ok = mid;
        else ng = mid;
        //cout << mid << " " << ok << " " << ng << " " << ok << endl;
    }
    return ok;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> Q;
    cin >> S;
    rep(i, Q) {
        cin >> t[i] >> d[i];
    }
    cout << binary_searchL() - binary_searchR()  + 1<< endl;



    return 0;
}
