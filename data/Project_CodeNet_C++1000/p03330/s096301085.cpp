#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
using VI = vector<int>;
using VII = vector<VI>;

int main() {
  int N, C;
  cin >> N >> C;
  VII Dif(C, VI(C));
  VII Grid(N, VI(N));
  REP(i, C) REP(j, C)
    cin >> Dif.at(i).at(j);
  REP(i, N) REP(j, N)
    cin >> Grid.at(i).at(j);
  
  VII SumDiff(C, VI(3));
  VI sum(3);
  REP(c, C) {
    sum.at(0)=0; sum.at(1)=0; sum.at(2)=0;
    REP(i, N) {
      REP(j, N) {
        sum.at((i+j)%3) += Dif.at(Grid.at(i).at(j)-1).at(c);
      }
    }
    SumDiff.at(c) = sum;
  }
  
  int min = SumDiff.at(0).at(0) + SumDiff.at(1).at(1) + SumDiff.at(2).at(2);
  REP(i, C) {
    REP(j, C) {
      if(j==i) continue;
      REP(k, C) {
        if(k==i || k==j) continue;
        int total = SumDiff.at(i).at(0) + SumDiff.at(j).at(1) + SumDiff.at(k).at(2);
        if(min > total) min = total;
      }
    }
  }
  cout << min << endl;
}