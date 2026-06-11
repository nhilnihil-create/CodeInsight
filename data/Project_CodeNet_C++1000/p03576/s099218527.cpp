//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
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
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
int n, k;
vector<p> x, y;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    for (int i = 0; i < n; i++)
    {
        ll tempx, tempy;
        cin >> tempx>>tempy;
        x.push_back(make_pair(tempx,tempy));
        y.push_back(make_pair(tempy,tempx));
    }
    sort(ALL(x));
    sort(ALL(y));
    ll ans=5000000000000000000;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int l=0;l<n-1;l++){
                for(int s=l+1;s<n;s++){
                    int count=0;
                    for(int h=0;h<n;h++){
                        if(x[h].first<=x[j].first&&x[h].first>=x[i].first)
                        {
                            if(x[h].second<=y[s].first&&x[h].second>=y[l].first)
                            {
                            count++;
                            }     
                        }                    
                    }
            if(count>=k)
            ans=min(ans,1LL*(x[j].first-x[i].first)*(y[s].first-y[l].first));
                }
            }
        }
    }
    
    cout << ans << "\n";
}

