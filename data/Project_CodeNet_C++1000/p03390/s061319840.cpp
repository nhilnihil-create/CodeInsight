// finish date: 2018/04/10

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>


int main() {
    int Q;
    cin >> Q;
    rep(k, Q) {
        int A, B;
        cin >> A >> B;
        int sq = (int) sqrt((ll) A * B);
        if ((int) sqrt((ll) A * B) * 2 == sqrt((ll) A * B) * 2) sq--;
        int ans = sq * 2;
        if (A != B) ans--;
        if ((ll) sq * (sq + 1) >= (ll) A * B) ans--;
        cout << ans << endl;
    }


    return 0;
}