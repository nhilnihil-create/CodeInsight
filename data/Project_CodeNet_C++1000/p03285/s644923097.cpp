#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  for(int i=0;i<=25;i++){
    for(int j=0;j<=15;j++){
      if(4*i+7*j==n){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}