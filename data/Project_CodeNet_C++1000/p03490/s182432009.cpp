#include <bits/stdc++.h>
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,b) for(int i=a; i<=b; i++)
using ll = long long;
#define pb push_back
class Position {
  public: 
    int x;
    int y;
    Position(int y, int x) {
      this->x = x;
      this->y = y;
    }
    Position(const Position& co) {
      this->x = co.x;
      this->y = co.y;
    }
    Position() {
      this->x = 0;
      this->y = 0;
    }
    bool equal(Position &a) {
      if ( (this->x == a.x) && (this->y == a.y) )
        return true;
      else 
        return false;
    }
};

int main()
{
  string s;
  int x,y;
  cin >> s;
  cin >> x >> y;
  set<int> hor;
  set<int> vec;
  vector<int> s_h;
  vector<int> s_v;

  int mod = 0; // for hor

  int i=0;
  while( i < s.size()) {
    int oldi = i;
    while ( (s[i] == 'F') && (i < s.size()) ) i++ ;
    if (mod == 0) {
      s_h.pb(i-oldi);
      mod = 1;
      i++;

    } else {
      s_v.pb(i-oldi);
      mod = 0;
      i++;
    }
  }

  hor.insert(s_h[0]);
  vec.insert(0);

  rep2(i,1, s_h.size()-1) {
    set<int> next_hor;
    for(auto c : hor) {
      next_hor.insert(c + s_h[i]);
      next_hor.insert(c - s_h[i]);
    }
    hor = next_hor;
  }


  rep(i, s_v.size()) {
    set<int> next_vec;
    for(auto c : vec) {
      next_vec.insert(c + s_v[i]);
      next_vec.insert(c - s_v[i]);
    }
    vec = next_vec;
  }



  if (  (hor.find(x) != hor.end()) && ((vec.find(y)) != vec.end()) ) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;

}