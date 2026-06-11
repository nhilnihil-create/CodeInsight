#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 3e5 + 7;
const int mod = 1e9 + 7;

void solve1()
{
    int n;
    cin >> n;
    vector < int > v(n + 2 , 0);
    for( int i = 1; i <= n; i++ ){
        cin >> v[i];
    }
    int sum = 0;
    for( int i = 1; i <= n; i++ ){
        sum = sum + abs(v[i] - v[i - 1]);
    }
    sum += abs(v[n]);
    for( int i = 1; i < n; i++ ){
        cout << sum - abs(v[i] - v[i - 1]) - abs(v[i] - v[i + 1]) + abs(v[i - 1] - v[i + 1]) << "\n";
    }
    cout << sum - abs(v[n]) + abs(v[n - 1]) - abs(v[n] - v[n - 1]);
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
