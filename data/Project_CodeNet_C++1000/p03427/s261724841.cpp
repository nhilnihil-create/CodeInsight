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

    string n;
    cin >> n;

    int s1 = 0;
    for ( auto l : n ) s1 += l - '0';
    int s = 0;
    s += n[0] - 1 - '0';
    for ( size_t i = 1; i < n.size(); i++ )  s+= 9;

    cout << max(s1, s) << endl;

    return 0;
}