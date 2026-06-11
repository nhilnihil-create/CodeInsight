#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  int Anum = 0, Bnum = 0, ABnum = 0, ans = 0;
  for (int i = 0; i < N; i++){
    string S;
    cin >> S;
    
    for (int j = 0; j < S.size() - 1; j++){
      if (S.at(j) == 'A' && S.at(j + 1) == 'B'){
        ans++;
      }
    }
    
    if (S.at(S.size() - 1) == 'A'){
      
      if (S.at(0) == 'B'){
        ABnum++;
      }
      else{
        Anum++;
      }
      
    }
    else{
    
      if (S.at(0) == 'B'){
        Bnum++;
      }
      
    }
    
  }
  
  ans += min(Anum, min(Bnum, N - 1));
  if (ABnum > 0){
    if (max(Anum, Bnum) > 0){
      ans += ABnum;
    }
    else{
      ans += ABnum - 1;
    }
  }
  cout << ans << endl;
}