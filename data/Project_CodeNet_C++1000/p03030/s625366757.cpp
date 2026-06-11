#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

struct info {
  string name;
  int score, order;
};

bool comp(const info& a, const info& b) {
  if (a.name != b.name) return a.name < b.name;
  return a.score > b.score;
}

int main() {
  int n;
  cin >> n;
  vector<info> infom(n);
  rep(i,n) {
    cin >> infom[i].name >> infom[i].score;
    infom[i].order = i+1;
  }
  sort(infom.begin(), infom.end(), comp);
  rep(i,n) printf("%d\n", infom[i].order);
  return 0;
}
