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
    cin >> s;

    int menor = INFINITO;
    for ( size_t i = 0; i < s.size() - 2; i++ ) {
        // cout << s.substr(i, i + 2) << endl;
        menor = min(menor, abs(753 - stoi(s.substr(i, 3))));
    }

    cout << menor << endl;

    return 0;
}