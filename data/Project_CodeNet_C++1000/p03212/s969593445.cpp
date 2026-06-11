#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll n,ans=0;
void dfs(ll x,ll a,ll b,ll c){
  if(x>n) return;
  if(a&&b&&c) ans++;
  dfs(x*10+3,1,b,c);
  dfs(x*10+5,a,1,c);
  dfs(x*10+7,a,b,1);
}

int main(){
  cin>>n;
  dfs(0,0,0,0);
  cout<<ans<<endl;
  return 0;
}
