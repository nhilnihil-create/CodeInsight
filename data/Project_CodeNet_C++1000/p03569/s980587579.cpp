#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
xけせばいい
xxaxxがあったか。そうか。
xadxxxaxxx
xxxaxxdxxaxxx
xaaxxa
もともとペアだったら2個ひけばいいか
だめだったか
*/
int main(){
  string s; cin>>s;
  ll ans=0;
  for(int i=0,j=s.size()-1; i<=j; i++){
    if(i>=j) break;
    while(s[i]!=s[j]){
      if(s[i]=='x'){
        i++;
        ans++;
      }
      else if(s[j]=='x'){
        j--;
        ans++;
      }
      else{
        cout<<-1<<endl;
        return 0;
      }
    }
    j--;
  }
  cout<<ans<<endl;
}