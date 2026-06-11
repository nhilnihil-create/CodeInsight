#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;  
  int East = 0;
  for(int i=0; i<n; i++){
    East += (s[i]=='E');
  }
  int ans = East;
  int tmp = East;
  for (int i=0; i<n; i++){
    if(s[i]=='E') tmp --;
    if(i>=1){
      if(s[i-1] =='W') tmp ++;
    }
  ans = ans>tmp?tmp:ans;
  }
  cout<<ans<<endl;
}