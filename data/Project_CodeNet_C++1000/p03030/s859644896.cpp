#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;

  pair<pair<string, int>, int> SPN[N];  //市名、点数、番号
  rep(i,N){
    string S; int P;
    cin >> S >> P;
    SPN[i] = make_pair(make_pair(S, - P), i);
  }

  sort(SPN, SPN + N);

  rep(i,N){
    cout << SPN[i].second + 1 << endl;
  }
}
