#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  int ans = 0;
  for (int pos = 0; pos < N; pos++){
    vector<bool> check(1000, false);
    int num = 0;
    
    for (int i = 0; i < pos; i++){
      check.at(S.at(i)) = true;
    }
    
    for (int i = pos; i < N; i++){
      if (check.at(S.at(i)) == true){
        num++;
        check.at(S.at(i)) = false;
      }
    }
    
    ans = max(ans, num);
  }
  
  cout << ans << endl;
}