#include<bits/stdc++.h>
#define eb emplace_back
typedef long long ll;

using namespace std;

signed main(void){
  
  int L; cin >> L;
  
  int a;
  
  for(int i = 0; i < 20; i++){ 
    if( (L >> i) & 1 ){ a = i;}
  }
  //a+1個のノードが必要
  
  vector<tuple<int,int,int>> ans;
  
  for(int i = 0; i < a; i++){
    ans.eb(i,i+1,0);
    ans.eb(i,i+1,pow(2,i));
  }
  
  int res = pow(2,a);
  for(int i = a-1; i >= 0; i--){ 
    if(  ( L >> i ) & 1 ){
      ans.eb(i,a,res);
      res += pow(2,i);
    }
  }
  
  cout << a+1 << " " <<  ans.size() << endl;
  
  for(auto ne : ans){
    cout << get<0>(ne)+1 << " " << get<1>(ne)+1 << " " << get<2>(ne) << endl;
  }
  
  return 0;
}
  