#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  



int main(){
  string s; cin >> s;
  vector<bool> a(26, false);
  for(int i=0; i<s.size();i++)  a[s[i]-'a'] = true;
  
  if(s.size()==26){
    string t=s;
    if(next_permutation(s.begin(), s.end())==0){
      cout << -1 << endl;
    }else{
      for(int i=0; i<26; i++){
        cout << s[i];
        if(s[i]!=t[i]){
          cout << endl; return 0;
        }
      }
    }
    
  }else{
    for(int i=0; i<26; i++){
      if(!a[i]){
        s += ('a'+i);
        cout << s << endl;
        break;
      }
    }
  }

  
    
}