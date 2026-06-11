#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  string S;
  cin>>S;
  int ans=0;
  int count=0;
  for(int i=0;i<(int)S.size();i++){
    if(i==0){
      if(S.at(i)=='A' || S.at(i)=='G' || S.at(i)=='C' || S.at(i)=='T'){
        count++;
        ans=max(count,ans);
      }
    }
    else{
      if(S.at(i)=='A' || S.at(i)=='G' || S.at(i)=='C' || S.at(i)=='T'){
        count++;
        ans=max(count,ans);
      }
      else{
        ans=max(count,ans);
        count=0;
      }
    }
  }
  cout<<ans<<endl;
}