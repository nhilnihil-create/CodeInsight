#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<bool>a(55555,true);
  
  a.at(0)==false;
  a.at(1)==false;
  
  
  rep2(i,2,55555){
    if(a.at(i)){
      for(int j=i*2;j<55555;j+=i){
        a.at(j)=false;
      }
    }
  }
 
  int ex=n;

  
    rep2(i,7,55555){
      if(a.at(i)){
        if(i%5==1){
          cout<<i<<" ";
          ex--;
          if(ex==0){
            break;
          }
        }
      }
    }
  
  
  
}
  



