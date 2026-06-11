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

    string s;
    ll k;
    cin >> s >> k;

    int ult1 = 0;
    int dif;
    for ( int i = 0; i < (int) s.size(); i++ ) {
        if ( s[i] != '1' ) {
            dif = s[i] - '0';
            break;
        }
        ult1++;
    }

    cout << (k <= ult1 ? 1 : dif) << endl;

    return 0;
}