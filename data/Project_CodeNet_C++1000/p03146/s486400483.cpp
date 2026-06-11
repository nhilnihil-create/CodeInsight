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

    int s;
    cin >> s;
    set<int> ns;
    ns.insert(s);

    s = (s & 1) ? 3 * s + 1 : s / 2;
    int i;
    for ( i = 2; ns.find(s) == ns.end(); i++) {
        ns.insert(s);
        s = (s & 1) ? 3 * s + 1 : s / 2;
    }

    cout << i << endl;

    return 0;
}