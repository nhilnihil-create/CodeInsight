#include<bits/stdc++.h>
using namespace std;
/*
long long solve(string s){
  long long n=0;
  for(int i=0;i<s.size();i++){
    for(int j=s.size()-1;j>0;j--){
      if(s.at(j)=='W'&&s.at(j-1)=='B'){
        swap(s.at(j),s.at(j-1));
        n++;
      }
    }
  }
  return n;
}
*/
int main(){
  string S;
  cin >> S;
  int64_t ans=0,b=0;
  for(int i=0,l=S.size();i<l;i++){
    if(S.at(i)=='B')
      b++;
    else
      ans+=b;
  }
  cout << ans << endl;
  return 0;
}