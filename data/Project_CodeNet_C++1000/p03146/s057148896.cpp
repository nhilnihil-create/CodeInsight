#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int s;
  cin>>s;
  map<int,int> mp;
  int tmp =1,ans;
  mp[s]=tmp;
  while(true){
    tmp++;
    if(s%2==0){
      s/=2;
      if(mp.count(s)){
        ans=tmp;
        break;
      }
      mp[s]=tmp;
    }else{
      s=3*s+1;
      if(mp.count(s)){
        ans=tmp;
        break;
      }
      mp[s]=tmp;
    }
  } 
  cout<<ans<<endl;
}