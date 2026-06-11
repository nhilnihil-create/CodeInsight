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

    int n, d, x;
    cin >> n >> d >> x;
    int acum = 0;
    fo(i, n) {
        int a;
        cin >> a;
        acum++;
        acum += ((d - 1) / a);
    }

    cout << acum + x << endl;

    return 0;
}