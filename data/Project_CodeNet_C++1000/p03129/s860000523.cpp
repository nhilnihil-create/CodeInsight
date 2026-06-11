#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 3e5 + 7;
const int mod = 1e9 + 7;

void solve1()
{
    int n,k;
    cin >> n >> k;
    if( (n + 1) / 2 >= k )cout << "YES";
    else cout << "NO";
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
