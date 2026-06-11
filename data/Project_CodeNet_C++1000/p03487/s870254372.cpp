#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> vec(n),ans(100000);
  rep(i,n){
    cin >> vec.at(i);
  }
  int64_t answer=0;
  for(int64_t x: vec){
    if(x>100000){
      answer++;
      continue;
    }
    ans.at(x-1)++;
  }
  rep(i,100000){
    if(ans.at(i)>=i+1){
      answer+=ans.at(i)-i-1;
    }else{
      answer+=ans.at(i);
    }
  }
  cout << answer;
}
   