#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  string s, ans;
  cin >> s;
  if(s[0]!='A'){
    cout << "WA" << endl;
    return 0;
  }
  if(isupper(s[1])){
    cout << "WA" << endl;
    return 0;
  }
  bool ok = false;
  for(int i=2; i<s.length()-1; i++){
    if(ok && isupper(s[i])){
      cout << "WA" << endl;
      return 0;
    }
    if(isupper(s[i])){
      if(s[i]=='C') ok = true;
      else{
        cout << "WA" << endl;
        return 0;
      }
    }
  }
  if(!ok){
    cout << "WA" << endl;
    return 0;
  }
  if(isupper(s[s.length()-1])){
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}
