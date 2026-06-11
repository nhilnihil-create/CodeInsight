#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  vector<int> ans(100000000,0);
  ans[s]++;
  for(int i=0;i<1000000;i++){
    if(s%2==0){
      s/=2;
      ans[s]++;
    }else{
      s=3*s+1;
      ans[s]++;
    }
    if(ans[s]==2){
      cout<<i+2<<endl;
      return 0;
    }
  }
}