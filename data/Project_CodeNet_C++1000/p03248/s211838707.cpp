#include<bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
int main(){
  string S;
  cin >> S;
  bool flag = true;
  int N = S.size();
  int par = 1;
  vector<P> ans(0);
  for(int i=0; i<N-1; i++){
    if(i == 0 && S[i] == '0'){
      flag = false;
    }
    if(S[i] != S[N-2-i]){
      flag = false;
    }
    P p = {par,i+2};
    ans.push_back(p);
    if(S[i] == '1' && i != 0){
      par = i+2;
    }
  }
  
  if(S[N-1] == '1'){
    flag = false;
  }
  
  if(flag){
    for(int i=0; i<N-1; i++){
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  else{
    cout << -1 << endl;
  }
}