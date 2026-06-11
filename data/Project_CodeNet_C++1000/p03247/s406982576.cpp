#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 2e5 + 7;
const ll mod = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll x[N];
ll y[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n;
    vector < int > v(2 , 0);
    for( int i = 1; i <= n; i++ ){
        cin >> x[i] >> y[i];
        v[(abs(x[i]) + abs(y[i])) % 2] += 1;
    }
    if( v[0] && v[1] ){
        cout << "-1\n";
        return 0;
    }
    vector < ll > jav;
    if( v[0] ){
        for( int i = 1; i <= n; i++ ){
            y[i] += 1;
        }
        jav.push_back(1);
    }
    for( int i = 0; i <= 30; i++ ){
        jav.push_back((1ll << i));
    }
    cout << (int)jav.size() << "\n";
    for( auto xx : jav ){
        cout << xx << " ";
    }
    cout << "\n";
    for( int i = 1; i <= n; i++ ){
        vector < char > res;
        for( int j = 30; j >= 0; j-- ){
            ll x1 = x[i] + (1ll << j);
            ll x2 = x[i] - (1ll << j);
            ll y1 = y[i] + (1ll << j);
            ll y2 = y[i] - (1ll << j);
            if( abs(x[i]) + abs(y1) < (1 << j) ){
                res.push_back('D');
                y[i] += (1 << j);
            }
            else if( abs(x[i]) + abs(y2) < (1 << j) ){
                res.push_back('U');
                y[i] -= (1 << j);
            }
            else if( abs(x1) + abs(y[i]) < (1 << j) ){
                res.push_back('L');
                x[i] += (1 << j);
            }
            else if( abs(x2) + abs(y[i]) < (1 << j) ){
                res.push_back('R');
                x[i] -= (1 << j);
            }
        }
        if( jav[0] == jav[1] ){
            res.push_back('D');
        }
        reverse( res.begin() , res.end() );
        for( auto x : res ){
            cout << x;
        }
        cout << "\n";
    }
}
