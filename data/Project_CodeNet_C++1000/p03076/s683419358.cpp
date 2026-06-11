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


bool comp( int a, int b ) {
    if ( !(a % 10) ) return true;
    if ( !(b % 10) ) return false;
    return (10 - (a % 10)) < (10 - (b % 10));
}


int main() {

    vi abcde(5);
    fo(i, 5) cin >> abcde[i];

    sort(all(abcde), comp);
    int at = 0;

    fo(i, 5) {
        if ( at % 10 ) at += (10 - (at % 10));
        at += abcde[i];
        // cout << at << endl;
    }

    cout << at << endl;

    return 0;
}