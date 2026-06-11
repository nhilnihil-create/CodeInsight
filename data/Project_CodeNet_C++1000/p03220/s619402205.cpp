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

    int t, n, a;
    cin >> n >> t >> a;
    int h;
    pii menor = {INFINITO, -1};

    fo(i, n) {
        cin >> h;
        int dist = abs(1000 * a - (1000 * t - h * 6));
        if ( dist < menor.ff ) {
            menor.ff = dist;
            menor.ss = i + 1;
        }
    }

    cout << menor.ss << endl;


    return 0;
}