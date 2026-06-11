#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string S;
  cin >> S;

  // erase(n,m) :: n文字目からm文字削除する
  // n:: 0-S.size()-1;
  // m:: Size() - まで

  bool flg = false;
  for(int n = 0; n <= S.size()-1; n++){
    for(int m = 0; m <= S.size()-n; m++){
      string T = S;
      if(T.erase(n,m) == "keyence"){
        flg = true;
        break;
      }
    }
    if(flg) break;
  }

  cout << (flg ? "YES" : "NO") << endl;

}
