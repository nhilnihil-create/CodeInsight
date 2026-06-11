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

    int n, m, x;
    cin >> n >> m >> x;
    set<int> a;

    fo(i, m) {
        int b;
        cin >> b;
        a.insert(b);
    }

    int custon = 0, custo0 = 0;
    int at = x;
    while ( at < n ) {
        at++;
        if ( a.find(at) != a.end() ) custon++;
    }
    at = x;
    while ( at > 0 ) {
        at--;
        if ( a.find(at) != a.end() ) custo0++;
    }

    cout << min(custon, custo0) << endl;

    return 0;
}