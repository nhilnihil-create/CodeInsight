#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  vector<int> a(N);
  vector<int> s(N+1);
rep(i, N){
    if(S[i] == 'W'){
      a[i] = 0;
    }else{
      a[i] = 1;
    }
  }
  s[0] = 0;
  //s_1, s_2, ..., s_Nに、それまでの和を格納
  rep(i, N){
    s[i+1] = s[i] + a[i];
  }
  int ans = 999999;
  for(int i = 1; i <= N; i++){
    int right = s[N] - s[i];
    int left = (i-1) - s[i-1];
    if(i == 1){
      ans = min(ans, right);
    }else if(i == N){
      ans = min(ans, left);
    }else{
      ans = min(ans, left + right);
    }
  }
  cout << ans << endl;
  return 0;
}
