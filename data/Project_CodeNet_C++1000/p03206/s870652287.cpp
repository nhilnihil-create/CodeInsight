#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)

//library----------------------------------------------


int main(){
  int D; cin>>D;
  if(D==22){
    printf("Christmas Eve Eve Eve\n");
  }
  else if(D==23){
    printf("Christmas Eve Eve");
  }
  else if(D==24){
    printf("Christmas Eve");
  }
  else{
    printf("Christmas");
  }
  return 0;
}