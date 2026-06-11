#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N;
  cin >> N;
  int vec[N][3];
  FOR(i,0,N) {
    cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
  }
  FOR(i,0,N-1) {
    int now = i;
    int artime = 0;
    while (now < N-1) {
      if (artime <= vec[now][1]) artime = vec[now][1]; //始発より先に着くなら、始発で出発
      else {
        while (artime % vec[now][2] != 0) artime++; //始発よりあとに着くなら、それ以降でFで割れる時に出発
      }
      artime += vec[now][0]; //次駅までの所要時間を足す
      now++;
    }
    cout << artime << endl;
  }    
  cout << 0 << endl; //最後の駅は例外
  return 0;
}