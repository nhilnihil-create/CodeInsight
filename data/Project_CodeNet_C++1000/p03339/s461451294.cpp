#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  //ここまで入力

  //i番目までで東，西を向いている人が何人いるか
  //実装の仕様上，1つ余分に配列を確保している
  int east_num[N+1] = {0};
  int west_num[N+1] = {0};
  rep(i, N){
    if(S[i] == 'E')
      east_num[i]++;
    else if(S[i] == 'W')
      west_num[i]++;
    east_num[i+1] = east_num[i];
    west_num[i+1] = west_num[i];
  }

   int count = 0;
  int ans = N;

  //1番左の人がリーダーのときは
  //2番目以降で東を向いている人を数えればよい
  ans = east_num[N-1] - east_num[0];

  //i番目の人を基準に，東と西を向いている人を数える
  count = 0;
  for(int i=1; i<N-1; i++){
    count += east_num[N-1] - east_num[i];
    count += west_num[i-1];
    //最小値の更新
    if(count < ans)
      ans = count;
    count = 0;
  }

  //1番右の人がリーダーのときは
  //N-1番目までの人で西を向いている人を数えればよい
  count = west_num[N-2];
  if(count < ans)
    ans = count;

  cout << ans << endl;
   
  return 0;
}
