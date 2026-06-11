#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int a=s.at(0)-'0';
  int l=s.size();
  bool ch=true;
  rep2(i,1,l){
    if(s.at(i)!='9'){
      ch=false;
      break;
    }
  }
  if(ch){
    int ans=a+9*(l-1);
    cout<<ans<<endl;
  }
  else{
    int ans=a-1+9*(l-1);
    cout<<ans<<endl;
  }
 
}