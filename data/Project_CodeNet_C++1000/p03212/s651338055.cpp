#include <bits/stdc++.h>
using namespace std;
int pow2(int x){
  int ans = 1;
  for (int i = 0; i < x; i++){
    ans *= 2;
  }
  return ans;
}
int pow3(int x){
  int ans = 1;
  for (int i = 0; i < x; i++){
    ans *= 3;
  }
  return ans;
}
string ternary(int x, int L){
  string ans;
  for (int i = 0; i < L; i++){
    ans += x % 3 + '0';
    x /= 3;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main(){
  int N;
  cin >> N;
  string S = to_string(N);
  int L = S.size();
  int ans = 0;
  for (int i = 1; i < L; i++){
    ans += pow3(i) - pow2(i) * 3 + 3;
  }
  for (int i = 0; i < pow3(L); i++){
    string T = ternary(i, L);
    string tmp;
    int cnt7 = 0;
    int cnt5 = 0;
    int cnt3 = 0;
    for (int j = 0; j < L; j++){
      if (T[j] == '0'){
        tmp += '7';
        cnt7++;
      }
      if (T[j] == '1'){
        tmp += '5';
        cnt5++;
      }
      if (T[j] == '2'){
        tmp += '3';
        cnt3++;
      }
    }
    if (cnt7 > 0 && cnt5 > 0 && cnt3 > 0 && tmp <= S){
      ans++;
    }
  }
  cout << ans << endl;
}