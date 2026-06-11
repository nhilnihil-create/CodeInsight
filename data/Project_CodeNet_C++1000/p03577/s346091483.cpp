/*  
    |\_/|
    |* *|
    \_+_/
*/
#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  string str;

  cin>>str;

  for(int i=0;i<str.length()-8;i++){
    cout<<str[i];
  }
  
  cout<<endl;
   
  return 0;
  
}


