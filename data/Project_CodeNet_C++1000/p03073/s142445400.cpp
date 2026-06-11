#include<iostream>
using namespace std;
int main(){
  string S;
  int ans=0;
  cin >> S;
  for(int i=1; i<S.length(); i++){
    if(S[i-1] == S[i]){
      ans++;
      if(S[i] == '0') S[i] = '1';
      else S[i] = '0';
    }
  }
  cout << ans << endl;
  return 0;
}
