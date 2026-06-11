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

    pii c1, c2;
    cin >> c1.ff >> c1.ss >> c2.ff >> c2.ss;

    cout << c2.ff + (c1.ss - c2.ss) << " " << c2.ss  + (c2.ff - c1.ff) << " ";
    cout << c1.ff + (c1.ss - c2.ss) << " " << c1.ss + (c2.ff - c1.ff) << endl;

    return 0;
}