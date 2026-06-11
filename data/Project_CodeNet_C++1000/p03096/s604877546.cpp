#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
int n;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;

    vector<ll> count(2*100000,0);
    ll dp[n+1];
    dp[0]=1;
    int before=-1;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        dp[i]=dp[i-1];
        if(before==temp)continue;
        before=temp;
        //if(count[temp].size()!=0){
            /*
            for(auto iter=count[temp].begin();iter!=count[temp].end();iter++){
                if(i-*iter>1){
                    dp[i]+=dp[*iter-1];
                    dp[i]%=MOD;
                }
            }
            */
        dp[i]+=count[temp];
        dp[i]%=MOD;
        //}
        count[temp]+=dp[i-1];
        count[temp]%=MOD;
    }
    cout << dp[n] << "\n";
}
