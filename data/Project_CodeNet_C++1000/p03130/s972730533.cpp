#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 3e5 + 7;
const int mod = 1e9 + 7;

int cnt;
bool used[N];
vector < int > v[N];

void dfs( int x )
{
    if( used[x] ){
        return;
    }
    used[x] = true;
    cnt++;
    if( cnt == 4 ){
        cout << "YES";
        exit(0);
    }
    for( int y : v[x] ){
        dfs(y);
    }
    cnt--;
}

void solve1()
{
    for( int i = 1; i < 4; i++ ){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for( int i = 1; i <= 4; i++ ){
        cnt = 0;
        dfs(i);
        for( int j = 1; j <= 4; j++ ){
            used[j] = false;
        }
    }
    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); srand(time(0));
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int cghf = 1;//cin >> cghf;
    while( cghf-- ){
        solve1();
    }
}
