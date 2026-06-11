#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll m,k;
  cin >> m >> k;

  if(k>=(ll)pow(2,m))cout << -1 << endl;
  else if(m==0){
    if(k==0)cout << 0 << " " << 0 << endl;
    else cout << -1 << endl;
  }
  else if(m==1){
    if(k==0)cout << 0 << " " << 1 << " " << 1 << " " << 0 << " " << endl;
    else cout << -1 << endl;
  }
  else{
    vec ans;
    for(ll i=0;i<(ll)pow(2,m);i++)if(i!=k)ans.push_back(i);
    ans.push_back(k);
    for(ll i=(ll)pow(2,m)-1;i>=0;i--)if(i!=k)ans.push_back(i);
    ans.push_back(k);
  
    for(ll i=0;i<ans.size();i++)cout << ans[i] << " ";
    cout << endl;
  }



  return 0;
}