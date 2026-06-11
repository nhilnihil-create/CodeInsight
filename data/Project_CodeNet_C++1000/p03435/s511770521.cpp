#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {

    vvi c(3, vi(3));

    fo(i, 3) fo(j, 3) cin >> c[i][j];

    bool pos = true;
    int dif = c[2][0] - c[2][1];
    fo(i, 2) {
        if ( c[i][0] - c[i][1] != dif ) pos = false;
    }
    dif = c[2][1] - c[2][2];
    fo(i, 2) {
        if ( c[i][1] - c[i][2] != dif ) pos = false;
    }

    cout << (pos ? "Yes\n" : "No\n");

    return 0;
}