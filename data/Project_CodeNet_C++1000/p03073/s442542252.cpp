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

    string s;
    cin >> s;
    int cont = 0;

    for ( size_t i = 0; i < s.size() - 1; i++ ) {
        if ( s[i] == s[i + 1] ) {
            s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}