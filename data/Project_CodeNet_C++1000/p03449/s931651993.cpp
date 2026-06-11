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

int main() {

    int n;
    cin >> n;
    vi acum1(n), acum2(n);
    cin >> acum1[0];
    fo(i, n - 1) {
        int a;
        cin >> a;
        acum1[i + 1] = acum1[i] + a;
    }

    cin >> acum2[0];
    fo(i, n - 1) {
        int a;
        cin >> a;
        acum2[i + 1] = acum2[i] + a;
    }

    int maior = 0;
    for ( int i = 0; i < n; i++ ) {
        int aux = 0;
        aux += acum1[i] + acum2[n - 1];
        if ( i > 0 ) {
            aux -= acum2[i - 1];
        }
        maior = max(aux, maior);
    }

    cout << maior << endl;

    return 0;
}