#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  //input
  int N;
  cin >> N;
  vector <int> L(N);
  rep(i,N) cin >> L[i];

  //solve
  sort(all(L));
  if (L[N - 1] < accumulate(all(L), 0) - L[N - 1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
