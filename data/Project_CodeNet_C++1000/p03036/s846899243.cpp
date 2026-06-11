#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int r,D,x;
  cin>>r>>D>>x;
  int cnt=0;
  while(cnt<10){
      x=r*x-D;
      cout<<x<<endl;
      cnt++;
  }
  
  
}