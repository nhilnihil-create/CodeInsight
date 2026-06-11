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

    int n;
    string s;
    cin >> n >> s;

    int maior = -1;

    for ( int i = 1; i < n; i++ ) {
        string r = s.substr(0, i), t = s.substr(i, n - i);
        // cout << r << " <- r t -> " << t << endl;
        set<char> letras;

        for ( auto l : r ) {
            letras.insert(l);
        }
        int cont = 0;
        for ( auto l : t ) {
            if ( letras.find(l) != letras.end() ) {
                cont++;
                letras.erase(l);
            }
        }
        maior = max(cont, maior);
    }

    cout << maior << endl;

    return 0;
}