#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int a,b;
  cin >> a >> b;
  
  string s;
  cin >> s;
  
  if(s[a] != '-'){
    cout << "No" << endl;
    return 0;
  }
  
  for(int i = 0; i < a+b+1; i++){
    if(i == a){
      continue;
    }
    if( !((s[i] - '0') >= 0 && (s[i] - '0') <= 9) ){
      cout << "No" << endl;
      return 0;
    }
  }//for
  
  cout << "Yes" << endl;
}