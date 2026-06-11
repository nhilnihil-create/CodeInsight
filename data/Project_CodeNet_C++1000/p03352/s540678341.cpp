#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int x;
  cin >> x;

  int max=1;
  int ans;
  rep(i,x){
    ans=1;
    rep(j,x){
      if(j<1)continue;
      ans*=(i+1);
      if(ans>x)break;
      else if(ans>max && j>1)max=ans;
    }
  }

  cout << max << endl;  
}