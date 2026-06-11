#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 1e6 + 7;
const ll mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll s[N];
pair < ll , int > d[N];
ll dd[N];
ll p[N];
vector < int > v[N];
map < ll , int > m;

void dfs( int x , int p )
{
    s[x] = 1;
    for( auto y : v[x] ){
        if( y == p )continue;
        dfs( y , x );
        s[x] += s[y];
    }
}

void foo( int x , int p , int val )
{
    dd[1] += val;
    for( auto y : v[x] ){
        if( y == p )continue;
        foo( y , x , val + 1 );
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> d[i].fi;
        d[i].se = i;
        m[d[i].fi] = i;
    }
    sort( d + 1 , d + n + 1 );
    reverse( d + 1 , d + n + 1 );
    for( int i = 1; i < n; i++ ){
        int x = d[i].se;
        ll sum = d[i].fi + 2 * s[x] + 2 - n;
        if( m.find(sum) == m.end() || sum > d[i].fi ){
            cout << "-1\n";
            return 0;
        }
        int y = m[sum];
        v[x].push_back(y);
        v[y].push_back(x);
        s[y] += s[x] + 1;
    }
    dfs( 1 , 1 );
    foo( 1 , 1 , 0 );
    queue < int > g;
    g.push(1);
    vector < int > used(n + 1,  0);
    used[1] = 1;
    while( !g.empty() ){
        int x = g.front();
        g.pop();
        for( auto y : v[x] ){
            if( used[y] ){
                if( p[x] == y )continue;
                if( dd[y] != dd[x] - s[y] + (n - s[y]) ){
                    cout << "-1\n";
                    return 0;
                }
            }else{
                p[y] = x;
                used[y] = true;
                g.push(y);
                dd[y] = dd[x] - s[y] + n - s[y];
            }
        }
    }
    sort( d + 1 , d + n + 1 , [&](pair < ll , int > a, pair < ll , int > b ){
        return a.se < b.se;
    });
    for( int i = 1; i <= n; i++ ){
        if( d[i].fi != dd[i] ){
            cout << "-1\n";
            return 0;
        }
        used[i] = 0;
    }
    for( int i = 1; i <= n; i++ ){
        used[i] = 1;
        for( auto x : v[i] ){
            if( used[x] )continue;
            cout << i << " " << x << "\n";
        }
    }
}
