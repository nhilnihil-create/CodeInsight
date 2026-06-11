#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[200005]={0};
vector<ll> col_pos[200005];
ll col[200005]={0};
int main(){
  ll n;
  cin>>n;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    col[i]=a;
    col_pos[a].push_back(i);
  }
  dp[1]=1;
  for(int i=1;i<=n;i++){
    dp[i+1]+=dp[i];
    dp[i+1]%=mod;

    ll n_col=col[i];
    ll pos=lower_bound(col_pos[n_col].begin(),col_pos[n_col].end(),i)-col_pos[n_col].begin();
    pos++;
    if(pos==col_pos[n_col].size()) continue;
    if(col_pos[n_col][pos]-i<=1) continue;
    ll npos=col_pos[n_col][pos];
    dp[npos]+=dp[i];
    dp[npos]%=mod;
  }
  cout<<dp[n]<<endl;
}
