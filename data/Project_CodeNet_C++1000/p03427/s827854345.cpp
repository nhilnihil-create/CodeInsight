#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;


int main(){
  ll N;
  ll max_val = 0;
  cout << setprecision(10);
  cin >> N;

  string S = to_string(N);

  max_val = (S.size()-1) * 9; //ベースライン

  ll tmp = 0;
  for(ll i = 0; i < S.size(); i++){
    // 残りの桁数は、S.size()-i
    if(S[i] == '0'){
      // そのまま
      continue;
    } else{
      // 1つ下げて残りを9
      ll now = S[i] - '0';
      ll now_val = tmp + (now-1) + 9 * (S.size() - 1 - i);
      if(max_val < now_val){
        max_val = now_val;
      }
      // そのまま
      tmp += S[i] - '0';
    }

    if(i == S.size()-1){
      max_val = max(max_val, tmp);
    }
  }
  cout << max_val << endl;

}
