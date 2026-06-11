#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  string S;
  cin>>S;
  int ans=0;
  int count=0;
  for(int i=1;i<=(int)S.size();i++){//i文字含む
    //cout<<i<<endl;
    for(int j=0;j<(int)S.size()-i+1;j++){//スタート
      //cout<<" "<<j<<endl;
      int count=0;
      for(int k=j;k<j+i;k++){
        //cout<<"   "<<k<<endl;
        if(S.at(k)=='A' || S.at(k)=='G' || S.at(k)=='C' || S.at(k)=='T'){
          count++;
        }
      }
      if(count==i){
        ans=max(ans,count);
      }
    }
  }
  cout<<ans<<endl;
}