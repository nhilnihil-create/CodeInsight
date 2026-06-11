#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    size_t m =a.length(), n = b.length();
    int dp[m+1][n+1];
    for (size_t i = 0 ; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (size_t i = 0 ; i <= n; i++) {
        dp[0][i] = 0;
    }
    int ans = 0;
    string ansstr = "";
    for (size_t i = 1 ; i <= m; i++) {
        for (size_t j = 1 ; j <= n; j++) {
            ans = 0;
            if (a[i-1] == b[j-1]) {
                ans = 1 + dp[i-1][j-1];
            }
            ans = max(ans, dp[i-1][j]);
            ans = max(ans, dp[i][j-1]);
            dp[i][j] = ans;
        }
    }
    size_t temp = ans, i = m, j = n;
    while(temp > 0){
        while (dp[i][j] == temp) {
            i--;
        }
        i++;
        while (dp[i][j] == temp) {
            j--;
        }
        j++;
        temp--;
        ansstr.push_back(a[i-1]);
        i--;
        j--;
    }
    int l = ans;
    for (i = 0 ; i < l; i++) {
        std::cout << ansstr[l-i-1];
    }
    std::cout << endl;
    return 0;
}

