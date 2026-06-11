#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  int N;cin>>N;
  if(N==3){
    cout<<"2 5 63"<<endl;
    return 0;
  }
  vector<int> v;
  for(int i=2;i<=30000;i++){
    if(i%2==0||i%3==0) v.push_back(i);
  }
  ll sum=0;
  vector<int> ans;
  for(int i=0;i<N-1;i++){
    ans.push_back(v[i]);
    sum+=1LL*v[i];
  }
  for(int i=N-1;i<v.size();i++){
    if((sum+1LL*v[i])%6==0){
      ans.push_back(v[i]);
      break;
    }
  }
  if(ans.size()==N-1){
    ans.pop_back();
    sum-=1LL*v[N-2];
    for(int i=N-2;i<v.size()-1;i++){
      bool flag=0;
      for(int j=i+1;j<v.size();j++){
        if((sum+1LL*(v[i]+v[j]))%6==0){
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          flag=1;
          break;
        }
      }
      if(flag==1) break;
    }
  }
  rep(i,N-1) cout<<ans[i]<<" ";
  cout<<ans[N-1]<<endl;
  return 0;
}
