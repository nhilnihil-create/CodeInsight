#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> city;
  vector<tuple<int, int, int>> IDs;
  int ID1, ID2;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    city.emplace_back(a, b, i);
  }
  sort(city.begin(), city.end());
  int P = 0, L = 0;

  REP(i, M) {
    ID1 = get<0>(city.at(i));
    if (L != ID1) {
      P = 0;
      L = ID1;
    }
    P++;
    ID2 = P;
    IDs.emplace_back(get<2>(city.at(i)), ID1, ID2);
  }
  sort(IDs.begin(), IDs.end());
  REP(i, M) printf("%06d%06d\n", get<1>(IDs.at(i)), get<2>(IDs.at(i)));
}