#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  cin >> N >> s;
  int tb=0;
  int tw=0;
  for(int i=0;i<N;i++){
    if(s.at(i)=='#'){
      tb++;
    }else{
      tw++;
    }
  }
  int64_t ans;
  int cb=0;
  int cw=0;
  ans=tw;
  if(s.at(0)=='#'){
    cb++;
  }else{
    cw++;
  }
  for(int i=1;i<N;i++){
    if(s.at(i)!=s.at(i-1)){
      int sum=cb+(tw-cw);
      if(ans>sum){
        ans=sum;
      }
    }
    if(s.at(i)=='#'){
      cb++;
    }else{
      cw++;
    }
  }
  if(ans>tb){
    ans=tb;
  }
  cout << ans << endl;
  return 0;
}
