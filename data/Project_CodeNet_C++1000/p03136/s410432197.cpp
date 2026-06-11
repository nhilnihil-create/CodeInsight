#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<int> L(N);

  for (int i = 0; i < N; i++)
  {
    cin >> L.at(i);
  }
  

  sort(L.begin(), L.end());

  int sum = 0;

  for (int i = 0; i < N - 1; i++){
    sum += L.at(i);
  }

  cout << (sum > L.at(N - 1) ? "Yes" : "No") << endl;
}