#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

long long MOD = 1000000007;

int main(){
  long long N;
  string S;
  cin >> N >> S;
  // 入力終了

  // アルファベットが何回出現したか
  long long cnt[26] = {0};
  rep(i, N){
    cnt[ S[i]-'a' ]++;
  }

  // 各アルファベットがcnt[i]回出現するので，
  // それを選ぶならcnt[i]通りと，選ばないという1通りがある
  long long ans = 1;
  rep(i, 26)
    ans = ( ans*(cnt[i]+1) )%MOD;

  // 何も選ばないときと，初期化の1を引く
  cout << ans-1 << endl;
    
  return 0;
}
