#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int a[1 << 18];
int dp[1 << 18][2][2];
int n;

void dfs(int x){
    dp[x][0][0] = a[x];
    dp[x][0][1] = x;
    dp[x][1][0] = a[0];
    dp[x][1][1] = 0;
    if(dp[x][0][0] < dp[x][1][0]){
        swap(dp[x][0][0], dp[x][1][0]);
        swap(dp[x][0][1], dp[x][1][1]);
    }
    vector<int> v;
    int x_ = x;
    rep(i,n){
        if(x_ % 2 == 1){
            v.push_back(pow(2,i));
        }
        x_ /= 2;
    }
    if(v.size() != 1){
        rep(i,v.size()){
            int y = x ^ v[i];
            if(dp[y][0][0] == -1){
                dfs(y);
            }
            vector<P> p;
            p.push_back(P(dp[x][0][0], dp[x][0][1]));
            p.push_back(P(dp[x][1][0], dp[x][1][1]));
            if(dp[y][0][1]!=dp[x][0][1] && dp[y][0][1]!=dp[x][1][1]){
                p.push_back(P(dp[y][0][0], dp[y][0][1]));
            }
            if(dp[y][1][1]!=dp[x][0][1] && dp[y][1][1]!=dp[x][1][1]){
                p.push_back(P(dp[y][1][0], dp[y][1][1]));
            }
            sort(p.begin(), p.end(), greater<P>());
            dp[x][0][0] = p[0].first;
            dp[x][0][1] = p[0].second;
            dp[x][1][0] = p[1].first;
            dp[x][1][1] = p[1].second;
        }   
    }
}

int main() {
    cin >> n;
    rep(i,(1<<n))cin >> a[i];

    rep(i,(1<<n)){
        dp[i][0][0] = -1;
    }

    dfs((1<<n) - 1);
    int ans[1<<n] = {};
    srep(i,1,(1<<n)){
        ans[i] = max(ans[i-1], dp[i][0][0] + dp[i][1][0]);
        cout << ans[i] << endl;
    }

    return 0;
}
 
 
