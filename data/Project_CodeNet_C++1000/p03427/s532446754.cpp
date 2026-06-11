#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  string s=to_string(N);
  if(s.size()==1){
    cout << N << endl;
    return 0;
  }
  s=string(s.size()-1,'9');
  for(int i=9;i>=0;i--){
    if(stoll((char)(i+'0')+s)<=N){
      cout << s.size()*9+i << endl;
      return 0;
    }
  }
  return 0;
}
