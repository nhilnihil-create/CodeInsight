#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
typedef long long int ll;
const int MOD=1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

  
int main(){

  int n,k;cin>>n>>k;
  vector<int> cl(n,0);
  int l=0,cnt=0;
  rep(i,n){
    int a;cin>>a;a--;
    cl[a]++;
  }
  //rep(i,n)cout<<cl[i]<<endl;
  sort(cl.begin(),cl.end());
  reverse(cl.begin(),cl.end());
  rep(i,n){
    if(cl[i]==0)continue;
    else if(cnt<k){
      cnt++;
    }
    else{
      cnt++;
      l+=cl[i];
    }
  }
  cout<<l<<endl;
  return 0;
}