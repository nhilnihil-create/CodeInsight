#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

int query(int i){
    cout << i << endl;
    string s;
    cin >> s;
    if(s == "Male") return 1;
    else if(s == "Female") return 2;
    else exit(0);
}

int main(){
  int n; cin >> n;
  vector<int> s(n);

  int l = 0;
  int r = n-1;

  s[l] = query(l);
  s[r] = query(r);


  while(1){
      int mid = (l + r) / 2;
      s[mid] = query(mid);

      if(s[l] != s[mid] && (mid - l) % 2 == 0) {
          r = mid;
      }
      else if(s[l] == s[mid] && (mid - l) % 2 == 1){
          r = mid;
      }
      else{
          l = mid;
      }
  }
  return 0;
}
