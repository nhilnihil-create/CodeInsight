#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const ll mod = 1e9+7;

int main() {
    int n,m; // 数列のサイズとクエリの数
    cin>>n>>m;

    vector<int> b(m);
    vector<int> a(m);

  //  vector<int> v(m);
    vector<int> v={2,5,5,4,5,6,3,7,6};
    rep(i,m){
      //int a1;
      cin>>b[i];
    }
    sort(b.rbegin(),b.rend());

    rep(i,m) a[i]=v[(b[i]-1)];
    vector<int> dp(20000);
    rep(i,20000)dp[i]=-INF;
    dp[0]=0;
    rep(i,n){
      rep(j,m){
        dp[i+a[j]]=max(dp[i]+1,dp[i+a[j]]);
      }
    }
    int D=dp[n];
    vector<int> ans(D);
    int res=n;


    rep(i,D){
      rep(j,m){
        if (res-a[j]<0) continue;
        if (dp[res-a[j]]+1==dp[res]){
          ans[i]=b[j];
          res-=a[j];
          break;
        }

      }
    }
    rep(i,D)cout<<ans[i];



}
