#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int cnt = 0;
  int div_cnt;
  for (int i = 1; i < N + 1; i++)
  {
    div_cnt = 0;
    for (int j = 1; j < i + 1; j++)
    {
      if (i % j == 0 && i % 2 == 1){
        div_cnt += 1;
      }
    }
    if (div_cnt == 8) cnt += 1;
  }
  cout << cnt << endl;
}