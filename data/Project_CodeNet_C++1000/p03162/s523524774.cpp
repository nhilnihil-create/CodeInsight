#include <bits/stdc++.h>
#include <iostream>
#include <string>

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
int rmove[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
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

struct Info
{
    int a, b, c;
};

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many;

    Info arr[many];
    for(int i = 0; i < many; i++)
        cin >> arr[i].a >> arr[i].b >> arr[i].c;

    int dp[many + 1][3];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= many; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
                dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i - 1].a;
            else if(j == 1)
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i - 1].b;
            else
                dp[i][j] = max(dp[i - 1][1], dp[i - 1][0]) + arr[i - 1].c;
        }
    }

    cout << max(dp[many][0], max(dp[many][1], dp[many][2])) << endl;

    //
    return 0;
}