#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 1e5 + 7;
const int M = 107;
const ll mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
int a[N];
int d[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n >> k;
    for( int i = 1; i <= n; i++ )cin >> a[i];
    d[0] = 2;
    for( int i = 1; i <= k; i++ ){
        d[i] = 2;
        for( int j = 1; j <= n; j++ ){
            if( a[j] > i )continue;
            if( d[i - a[j]] == 2 ){
                d[i] = 1;
                break;
            }
        }
    }
    if( d[k] == 1 )cout << "First";
    else cout << "Second";
}
