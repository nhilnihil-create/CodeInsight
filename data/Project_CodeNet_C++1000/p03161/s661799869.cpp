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

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many >> number;

    int arr[many];
    for(int i = 0; i < many; i++)
        cin >> arr[i];

    int dp[many];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for(int i = 0; i < many; i++)
    {
        for(int j = i + 1; j <= i + number && j < many; j++)
        {
            if(dp[j] == -1)
                dp[j] = dp[i] + abs(arr[j] - arr[i]);
            else
                dp[j] = min(dp[i] + abs(arr[j] - arr[i]), dp[j]);
        }
    }

    // for(int i = 0; i < many; i++)
    //     cout << dp[i] << " ";
    // cout << endl;

    cout << dp[many - 1] << endl;

    //
    return 0;
}