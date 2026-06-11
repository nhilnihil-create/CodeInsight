#include <bits/stdc++.h>

using namespace std;

int main(){
  string s, t;
  cin >> s >> t;

  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());
  int cnt = 0;

  while(1){
    int i = (int)s[cnt];
    int j = (int)t[cnt];
    if(i == 0 & j == 0){
      cout << "No" << endl;
      break;
    }
    if(i < j){
      cout <<"Yes" << endl;
      break;
    }else if(i > j){
      cout  <<"No" << endl;
      break;
    }
    cnt++;
    


  }
}
