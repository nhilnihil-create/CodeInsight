#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, X;
  cin >> N >> X;

  vector<int> m(N);

  for (int i = 0; i < N; i++)
  {
    cin >> m.at(i);
  }

  int cnt = 0;

  for (int i = 0; i < N; i++)
  {
    X -= m.at(i);
    cnt += 1;
  }

  sort(m.begin(),m.end());

  cnt += X / m.at(0);
  
  cout << cnt << endl;  
}