#include<bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i<(int64_t)(n);i++)
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<int> diffcnt(n+1);
  int mincnt = 0;
  for(int i=0;i < n;i++){
    if(s.at(i) == '.'){
      diffcnt.at(0)++;
    }
  }
  mincnt = diffcnt.at(0);
  rep(i,n){
    if(s.at(i) == '.'){
      diffcnt.at(i+1) = diffcnt.at(i) - 1;
    }else{
      diffcnt.at(i+1) = diffcnt.at(i) + 1;
    }
    mincnt = min(mincnt,diffcnt.at(i+1));
  }
      
    
  cout << mincnt << endl;
}
    
      
    
