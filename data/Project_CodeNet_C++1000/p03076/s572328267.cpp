//難しかった

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int maxtime(int x){
  return (x + 9) / 10 * 10;
}
int remtime(int x){
  return maxtime(x) - x;
}
int main(void){
  vector <int> A(5);
  rep(i,5) cin >> A[i];

  int sum = 0;
  rep(i,5) sum += maxtime(A[i]);
  sum -= max({remtime(A[0]), remtime(A[1]), remtime(A[2]), remtime(A[3]), remtime(A[4]) });
  cout << sum << endl;

}
