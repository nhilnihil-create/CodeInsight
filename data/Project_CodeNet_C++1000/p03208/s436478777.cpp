#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INFINITO 1000000000
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


int main() {

    int n, k;
    cin >> n >> k;
    vi h(n);
    fo(i, n) cin >> h[i];

    int menor = INFINITO;
    sort(all(h));
    for ( int i = 0; i < n - k + 1; i++ ) {
        menor = min(h[i + k - 1] - h[i], menor);
        // cout << h [i + k - 1] << endl;
    }

    cout << menor << endl;

    return 0;
}