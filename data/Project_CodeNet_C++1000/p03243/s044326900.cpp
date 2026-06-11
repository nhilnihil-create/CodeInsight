#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  rep(i,10){
    if(111*i>=n){
      cout<<111*i<<endl;
      return 0;
    }
  }
}