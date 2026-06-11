#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<int>Ans(S.size());
  for(int i=0;i<S.size();++i){
    if('A' ==S[i] || 'C'==S[i] || 'G'==S[i] || 'T'==S[i]){
      if(i==0){
        Ans[i]=1;
      }
      else{
        Ans[i]=Ans[i-1]+1;
      }
    }
    else{
      Ans[i]=0;
    }
  }
  int ans=0;
  for(int i=0;i<S.size();++i){
    ans = max(ans,Ans[i]);
  }
  cout << ans << endl;
}
