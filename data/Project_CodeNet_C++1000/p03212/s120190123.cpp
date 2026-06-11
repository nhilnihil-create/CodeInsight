#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> vec;

void dfs(ll x){
  if(x<1e11){
    vec.push_back(x*10+7);
    dfs(x*10+7);
    vec.push_back(x*10+5);
    dfs(x*10+5);
    vec.push_back(x*10+3);
    dfs(x*10+3);
  }
}
bool wh(ll x){
  int a=0,b=0,c=0;
  while(x>0){
    if(x%10==7){
      a++;
    }
    if(x%10==5){
      b++;
    }
    if(x%10==3){
      c++;
    }
    x/=10;
  }
  if(a>0&&b>0&&c>0){
    return true;
  }
  else{
    return false;
  }
}
  
int main(){
  vec.push_back(0);
  dfs(0);
  sort(vec.begin(),vec.end());
  ll n;
  cin>>n;
  int ans=0;
  for(int i=0;i<vec.size();i++){
    if(vec[i]>n){
      break;
    }
    if(wh(vec[i])==true){
      ans++;
    }
  }
  cout<<ans<<endl;
}