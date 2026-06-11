#include <bits/stdc++.h>
using namespace std;
int main(){
  int L;
  cin >> L;
  int N = 20;
  vector<tuple<int, int, int>> E;
  for (int i = 0; i < N - 1; i++){
    E.push_back(make_tuple(i, i + 1, 0));
  }
  for (int i = 0; i < N - 1; i++){
    if (L >= 1 << (i + 1)){
      E.push_back(make_tuple(i, i + 1, 1 << i));
    }
  }
  int cnt = 0;
  int tmp = 1;
  while (tmp * 2 < L){
    tmp *= 2;
    cnt++;
  }
  for (int i = 0; i < cnt; i++){
    if (L >> i & 1){
      L -= (1 << i);
      E.push_back(make_tuple(i, N - 1, L));
    }
  }
  int M = E.size();
  cout << N << ' ' << M << endl;
  for (int i = 0; i < M; i++){
    int v = get<0>(E[i]);
    int w = get<1>(E[i]);
    int d = get<2>(E[i]);
    cout << v + 1 << ' ' << w + 1 << ' ' << d << endl;
  }
}