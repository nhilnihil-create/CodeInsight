#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  char s[3][3];
  rep(i,3){
    rep(j,3){
      cin>>s[i][j];
    }
  }
  rep(i,3)cout<<s[i][i];
}