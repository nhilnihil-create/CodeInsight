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

    string s, t;
    cin >> s >> t;

    for ( size_t i = 0; i < s.size(); i++ ) {
        s = s.back() + s.substr(0, (int) s.size() - 1);
        // cout << s << endl;
        if ( s == t ) {
            cout << "Yes\n";
            return 0;
        }
    }
    if ( s != t ) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}