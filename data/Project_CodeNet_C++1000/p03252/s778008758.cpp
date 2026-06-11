#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int main(void){
  string s,t; cin >> s >> t;

  int n = 26;
  vector<int> start(n,-1);
  vector<int> to(n,-1);

  rep(i,s.size()){
    int a = s[i]-'a';
    int b = t[i]-'a';

    if(start[a] != -1 && start[a] != b){      
      cout << "No" << endl;
      return 0;
    }
    if(to[b] != -1 && to[b] != a){
      cout << "No" << endl;
      return 0;
    }
    else{
      start[a] = b;
      to[b] = a;
    }
  }
  cout << "Yes" << endl;
  
  return 0;
}
