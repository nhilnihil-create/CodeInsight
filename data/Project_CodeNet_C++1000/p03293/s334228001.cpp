#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  deque<char> sq, tq;
  rep(i, s.size()) sq.push_back(s.at(i));
  rep(i, t.size()) tq.push_back(t.at(i));
  rep(i, s.size()){
    if(sq == tq){
      cout << "Yes" << endl;
      return 0;
    }
    sq.push_front(sq.back());
    sq.pop_back();
  }
  cout << "No" << endl;
  return 0;
}