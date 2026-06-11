#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;

  if(S == "keyence"){
    cout << "YES" << endl;
  }
  else{
    for(int i = 0; i < 8; ++i){
      string S_tmp = S;
      if("keyence" == S_tmp.erase(i, S.size() - 7)){
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }

  return 0;
}
