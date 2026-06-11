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

    int n, m;
    cin >> n >> m;
    vector<set<int>> vs(n);

    fo(i, n) {
        int k;
        cin >> k;
        fo(j, k) {
            int a;
            cin >> a;
            vs[i].insert(a);
        }
    }

    int cont = 0;
    fo(i, m) {
        bool pos = true;
        fo(j, n) {
            if ( vs[j].find(i + 1) == vs[j].end() ) {
                pos = false;
                break;
            }
        }
        if ( pos ) cont++;
    }

    cout << cont << endl;

    return 0;
}