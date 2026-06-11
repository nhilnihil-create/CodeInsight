#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr char black= '#';
  constexpr char white= '.';

  int N;
  string S;
  cin >> N >> S;

  vector<int> left_b(N+1);
  for(int i=0; i<N; i++){
    int diff= (S.at(i)==black) ? 1
                               : 0;
    left_b.at(i+1)= left_b.at(i)+ diff;
  }

  const int Nblack= left_b.back();
  const int Nwhite= N- Nblack;
  // [0,i)を白, [i,N)を黒に塗ったときの手数を求め、最小値を出力
  int ans= N;
  for(int i=0; i<=N; i++){
    int right_w= N-i - (Nblack- left_b.at(i));
    int Nop= left_b.at(i)+ right_w;
    ans= min(ans, Nop);
  }

  cout << ans << endl;
}