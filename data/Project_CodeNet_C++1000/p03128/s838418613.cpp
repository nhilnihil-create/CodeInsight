#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x[10]={inf,2,5,5,4,5,6,3,7,6};
    int n,m;cin >> n >> m;
    vector<bool> b(10);
    rep(i,0,m){
        int a;cin >> a;
        b[a]=true;
    }
    vector<vector<bool>> dp(n+1,vector<bool>(n/2+1));
    dp[0][0]=true;
    rep(i,0,n){
        rep(j,0,n/2+1){
            if(!dp[i][j]){
                continue;
            }
            rep(k,1,10){
                if(i+x[k]<=n&&b[k]){
                    dp[i+x[k]][j+1]=true;
                }
            }
        }
    }
    int t=0;
    rep(i,0,n/2+1){
        if(dp[n][i]){
            chmax(t,i);
        }
    }
    vector<int> ans;
    int now=n;
    rrep(i,t-1,0){
        rrep(j,9,1){
            if(b[j]&&now-x[j]>=0&&dp[now-x[j]][i]){
                ans.push_back(j);
                now-=x[j];
                break;
            }
        }
    }
    for(int v:ans){
        cout << v;
    }
    cout << endl;
}