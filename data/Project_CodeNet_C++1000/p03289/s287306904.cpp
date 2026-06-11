#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s; cin>>s;
    if(s[0]!='A')
      cout << "WA" << endl;
    else if(s[1]<'a')
      cout << "WA" << endl;
    else if(s.back()<'a')
      cout << "WA" << endl;
    else{
      int c = 0;
      for(int i=2; i<s.size()-1; i++){
        if(s[i]<'a' && s[i]!='C'){
          cout << "WA" << endl;
          return 0;
        }
        if(s[i]=='C')c++;
      }
      if(c==1)cout << "AC" << endl;
      else cout << "WA" << endl;
    }
    return 0;
}
