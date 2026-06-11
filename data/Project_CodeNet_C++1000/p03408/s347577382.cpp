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

    int n, m;
    map<string, int> s, t;

    cin >> n;
    fo(i, n) {
        string a;
        cin >> a;
        s[a]++;
    }
    cin >> m;
    fo(i, m) {
        string a;
        cin >> a;
        t[a]++;
    }

    int maior = 0;
    for ( auto p : s ) {
        maior = max(p.ss - t[p.ff], maior);
    }

    cout << maior << endl;
    return 0;
}