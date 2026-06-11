#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = ((ll)(x) - 1); i >= 0; i--)

#define vi vector<int>
#define vvi vector<vi>

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define chmin(x,y) (x=min(x,y))
#define chmax(x,y) (x=max(x,y))

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const ll mod = 1e9 + 7;
const ll IMF = 1LL<<29;
const double PI = 3.14159265358979323846;


// ***************************CODE**********************//

const int N = 1e5 + 7;

bool vis[N][100];


int suma(int n)
{
        int res = 0;
        while(n > 0)
        {
                res += n % 10;
                n /= 10;
        }
        return res;
}

int n;

void dfs(int r, int s)
{
        if(s >= 99) return;
        if(vis[r][s]) return;
        vis[r][s] = 1;
        for(int i = 0; i < 10; i++)
                dfs((10*r + i) % n, s + i);
}

int main()
{
        _upgrade;
        cin >> n;
        for(int i = 0; i < n; i++)
                dfs(i, suma(i));
        int res = 1e9;
        for(int i = 1; i < 99; i++){
                if(vis[0][i]) res = min(res,i);
        }
        cout << res << endl;
        return 0;
}





