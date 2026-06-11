#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

bool flag[330][330][330];
int n;
double dp[330][330][330];
double dfs(int c1,int c2,int c3){
    if(c1+c2+c3==0) return dp[c1][c2][c3] = 0;
    if(flag[c1][c2][c3]) return dp[c1][c2][c3];
    flag[c1][c2][c3] = 1;
    double sum = c1+c2+c3;
    double ans = (double)n/sum;
    double a=0;
    if(c1 > 0) a += dfs(c1-1,c2,c3) * (double)c1/sum;
    ans = a + ans;
    if(c2 > 0) ans += dfs(c1+1,c2-1,c3) * c2/sum;
    if(c3 > 0) ans += dfs(c1,c2+1,c3-1) * c3/sum;
    return dp[c1][c2][c3] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> a(4,0);

    rep(i,n){
        int x;
        cin >> x;
        a[x]++;
    }

    double res = dfs(a[1],a[2],a[3]);
    cout << fixed << setprecision(10) << res << endl;


    cout << endl;
    return 0;
}
