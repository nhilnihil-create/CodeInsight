/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define X real()
# define Y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef complex < ld > point;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n;
string s;
map < pair < string, string >, int > m;

int main(){
  cin >> n >> s;
  for(int i = 0; i < (1 << n); ++i){
    string p1, p2;
    for(int j = 0; j < n; ++j){
      if((i >> j) & 1){
        p1 += s[j];
      } else{
        p2 += s[j];
      }
    }
    m[make_pair(p1, p2)]++;
  }
  ll ans = 0;
  for(int i = 0; i < (1 << n); ++i){
    string p1, p2;
    for(int j = 0; j < n; ++j){
      if((i >> j) & 1){
        p1 += s[j + n];
      } else{
        p2 += s[j + n];
      }
    }
    reverse(p1.begin(), p1.end());
    reverse(p2.begin(), p2.end());
    ans += m[make_pair(p1, p2)];
  }
  cout << ans;

  return 0;
}
