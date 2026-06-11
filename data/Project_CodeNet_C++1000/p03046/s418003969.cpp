#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  int m,k;
  cin>>m>>k;
  if(m==1){
    if(k==0)cout<<0<<' '<<0<<' '<<1<<' '<<1<<endl;
    else cout<<-1<<endl;
    return(0);
  }
  if(k>=(1<<m)){
    cout<<-1<<endl;
    return(0);
  }

  vector<int>ans;
  ans.push_back(k);
  rep(i,1<<m){
    if(i==k)continue;
    ans.push_back(i);
  }
  ans.push_back(k);
  for(int i=(1<<m)-1;i>=0;i--){
    if(i==k)continue;
    ans.push_back(i);
  }

  rep(i,ans.size()){
    cout<<ans[i];
    if(i+1==ans.size())cout<<endl;
    else cout<<' ';
  }

  return(0);
}


