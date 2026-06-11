#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 3e2 + 1;
const int M = 22;
const ll mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int a[N];
int b[N];
double ans[N][N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
        b[a[i]] += 1;
    }
    for( int i = 0; i <= n; i++ ){
        for( int j = 0; j <= n; j++ ){
            for( int h = 0; h <= n; h++ ){
                if( (i | j | h) == 0 )continue;
                int f = n - i - j - h;
                if( f < 0 )continue;
                double x1 = i * 1.0 / n;
                double x2 = j * 1.0 / n;
                double x3 = h * 1.0 / n;
                if( i ){
                    x1 *= ans[i - 1][j + 1][h];
                }
                if( j ){
                    x2 *= ans[i][j - 1][h + 1];
                }
                if( h ){
                    x3 *= ans[i][j][h - 1];
                }
                ans[i][j][h] = (x1 + x2 + x3 + 1) / (1.0 - f * 1.0 / n);
            }
        }
    }
    cout.precision(9);
    cout << fixed << ans[b[3]][b[2]][b[1]];
}
