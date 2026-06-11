#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
 
using namespace std;

const ll mod = 1000000007;    

ll tc, cnt = 0, number, many, total = 0, query;
// vector <vector <int> > adjList;
int rmove[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int cmove[8] = {0, 1, 0, -1, 1, -1, -1, 1};

ll power(ll x, ll y, ll mod)
{
    if(y == 0)
        return 1;
    else if(y % 2 == 0)
        return (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
    else
        return x * (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    int row, column;
    cin >> row >> column;
 
    char arr[row][column];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            cin >> arr[i][j];
 
    int dp[row][column];
    int modulo = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
 
    if(arr[0][0] == '.')
        dp[0][0] = 1;
 
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(arr[i][j] == '.')
            {
                if(i > 0)
                    (dp[i][j] += dp[i - 1][j]) %= modulo;
                if(j > 0)
                    (dp[i][j] += dp[i][j - 1]) %= modulo;
            }
        }
    }
 
//    for(int i = 0; i < row; i++)
//    {
//        for(int j = 0; j < column; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//    }

    cout << dp[row - 1][column - 1] << endl;

    //
    return 0;
}