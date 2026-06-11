#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N;
vector<int> A, B;
vector<pair<int, int>> AB;

bool cmp(pair<int, int> l, pair<int, int> r){
  return l.first + l.second < r.first + r.second;
}
int main(){
  cin >> N;
  A.resize(N), B.resize(N);
  AB.resize(N);
  REP(i, N){
    cin >> A[i] >> B[i];
    AB[i] = {A[i], B[i]};
  }
  ll taka = 0, ao = 0;
  sort(AB.rbegin(), AB.rend(), cmp);
  REP(i, N){
    if(i%2){
      ao += AB[i].second;
    }
    else{
      taka += AB[i].first;
    }
  }
  cout << taka - ao << endl;
  return 0;
}
