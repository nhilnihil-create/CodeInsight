#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9+10;

int main(){
  string s;
  cin >> s;

  int p = 0;
  int p_ref = 0;
  string ref = "AKIHABARA";
  while(!(p_ref == ref.size() && p == s.size())){
    if(s[p] == ref[p_ref]){
      p++;
      p_ref++;
    }else if(ref[p_ref] == 'A'){
      p_ref++;
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
