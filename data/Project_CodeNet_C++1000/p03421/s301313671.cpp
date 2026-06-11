#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  
  ll x=n-(a+b-1);
  if(x<0||x>(a-1)*(b-1)){
      cout<<-1<<endl;
      return 0;
  }

  if(a==1){
      if(b==n){
          for(int i=n;i>=1;i--) cout<<i<<" ";
          cout<<endl;
      }else cout<<-1<<endl;
      return 0;
  }else if(b==1){
      if(a==n){
          for(int i=1;i<=n;i++) cout<<i<<" ";
          cout<<endl;
      }else cout<<-1<<endl;
      return 0;
  }

  vector<int> ans;
  bool used[n+1]={};
  for(int i=b;i>=1;i--){
      ans.push_back(i);
      used[i]=true;
  }
  for(int i=n-(a-1)+1;i<=n;i++){
      ans.push_back(i);
      used[i]=true;
  }

  for(int k=1;;k++){
      int ma=n-(a-1)*k;
      if(ma<=0) break; 
      for(int i=ma-(a-1)+1;i<=ma;i++){
          if(i<=0) continue;
          if(used[i]) continue;
          ans.push_back(i);
          used[i]=true;
      }
  } 

  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
  cout<<endl;

  return 0;
}
