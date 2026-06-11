#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  int s;
  cin>>s;
  map<int,int>mp;
  int x=s;
  while(mp.count(x)==0){
    mp[x]=1;
    if(x%2==0){
      x/=2;
    }else{
      x=x*3+1;
    }
  }
  cout<<(mp.size()+1)<<endl;
  return 0;
}