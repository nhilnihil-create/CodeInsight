#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  string s;

  cin>>s;

  if(s.length()!=2){
    reverse(s.begin(),s.end());
  }
  
  cout<<s<<endl;

  return 0;

}
