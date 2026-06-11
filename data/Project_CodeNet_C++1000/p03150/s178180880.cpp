#include <bits/stdc++.h>
using namespace std;

int main(){
  const string keyword= "keyence";
  string S;
  cin >> S;

  bool is_satisfied= false;
  for(size_t len_head=0; len_head<= keyword.size(); len_head++){
    size_t len_tail= keyword.size()- len_head;
    if(S.substr(0, len_head)==keyword.substr(0, len_head) && S.substr(S.size()-len_tail)==keyword.substr(keyword.size()-len_tail)){
      is_satisfied= true;
      break;
    }
  }
  string ans= is_satisfied ? "YES"
                           : "NO";
  cout << ans << endl;
}