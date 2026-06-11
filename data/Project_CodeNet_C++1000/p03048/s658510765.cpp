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

    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;

    for ( int red = n / r; red >= 0; red-- ) {
        for( int green = 0; ; green++ ) {
            if ( red * r + green * g > n ) break;
            for ( int blue = 0; ; blue++ ) {
                if ( red * r + green * g + blue * b > n ) break;
                if ( red * r + green * g + blue * b == n ) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}