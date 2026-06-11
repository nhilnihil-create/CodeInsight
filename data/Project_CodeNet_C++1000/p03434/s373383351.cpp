#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> vec(N);
  rep(i,N) cin >> vec[i];

  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int Alice = 0, Bob = 0;
  for(int i = 0; i < N; i+=2){
    Alice += vec[i];
  }
  for(int i = 1; i < N; i+=2){
    Bob += vec[i];
  }

  int sa = Alice - Bob;
  cout << sa << endl;
}
