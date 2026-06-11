#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N=100010;
int main()
{
  struct Point {LL x, y;};
  LL N;
  cin >> N;
  vector<Point> P(N);
  for(auto& p: P) cin >> p.x >> p.y;

  auto parity = abs(P[0].x+P[0].y)&1;
  for(const auto& p: P) if((abs(p.x+p.y)&1) != parity) {
    cout << -1 << endl;
    exit(0);
  }

  auto m = 31ll;
  vector<LL> d;
  for(auto i=m-1; 0<=i; --i) d.emplace_back(1ll<<i);
  if(!parity) d.emplace_back(1ll), ++m;

  cout << m << endl;
  for(auto i: d) cout << (i==d.front() ? "" : " ") << i;
  cout << endl;
  for(const auto& p: P) {
    auto x = p.x;
    auto y = p.y;
    for(auto i: d) {
      if(abs(x)<abs(y)) {
        if(y<0) {y += i; cout << "D";}
        else    {y -= i; cout << "U";}
      } else {
        if(x<0) {x += i; cout << "L";}
        else    {x -= i; cout << "R";}
      }
    }
    cout << endl;
  }
}
