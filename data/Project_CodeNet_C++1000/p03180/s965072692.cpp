#include<bits/stdc++.h>
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define pb push_back
ll dp[70000];
ll mat[18][18];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>mat[i][j];
      }
    }
    int all = 1<<n;

    for(int i=0;i<all;i++){
        ll tmp = 0;
        for(int j=0;j<n;j++){
          if(!(i&(1<<j)))continue;
          for(int k=j+1;k<n;k++){
            if(!(i&(1<<k)))continue;
            tmp += mat[j][k];
          }
        }
        dp[i] = tmp;
        for(int mas =(i-1)&i;mas;mas=(mas-1)&i){
           //cout<<i<<" "<<mas<<'\n';
           dp[i] = max(dp[i],dp[mas]+dp[i^mas]);
        }
    }

    cout<<dp[all-1]<<'\n';


}
