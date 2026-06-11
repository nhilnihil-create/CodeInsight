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
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


int main() {

    int a, b, c, x;
    cin >> c >> b >> a >> x;

    int conta = 0;

    for ( int i = 0; i <= a; i++ ) {
        for ( int j = 0; j <= b; j++ ) {
            for ( int k = 0; k <= c; k++ ) {
                int aux = i * 50 + j * 100 + k * 500;
                if ( aux == x ) {
                    // cout << i << " <- i j -> " << j << "  k -> " << k << endl;
                    conta++;
                    break;
                } else if ( aux > x ) break;
            }
        }
    }

    cout << conta << endl;

    return 0;
}