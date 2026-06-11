#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// order statistics tree
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update> indexed_set;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int N = 1010;
int n;
ll in[N][2];
vector<ll> segments;
vector<string> ans;
int main() {
  cin.tie(0); cin.exceptions(cin.failbit);
  scanf("%d", &n);
  rep(i, 0, n){
    scanf("%lld%lld", &in[i][0], &in[i][1]);
  }

  ll mod2 = abs((in[0][0] + in[0][1])%2);
  bool possible = true;

  // check that they all have same parity
  rep(i,1, n){
    if(abs((in[i][0] + in[i][1])%2) != mod2){
      possible = false;
      break;
    }
  }

  if(possible){
    if(mod2 == 0){
      segments.PB(1);
    }
    rep(i, 0, 31){
      segments.PB(1LL << i);
    }
    rep(i, 0, n){
      ll x = in[i][0], y = in[i][1];

      int num_segs = sz(segments);
      ll sum = (1LL << 31) - mod2;
      string s("");
      for(int j = num_segs-1; j >= 0; j--){
        sum -= segments[j];
        if(abs(x - segments[j]) + abs(y) <= sum) {
          s += 'R';
          x -= segments[j];
        } else if(abs(x + segments[j]) + abs(y) <= sum){
          s += 'L';
          x += segments[j];
        } else if(abs(x) + abs(y - segments[j]) <= sum){
          s += 'U';
          y -= segments[j];
        } else {
          s += 'D';
          y += segments[j];
        }
      }

      reverse(s.begin(), s.end());
      ans.PB(s);
    }

    printf("%d\n", sz(segments));
    trav(l, segments){
      printf("%lld ", l);
    }
    puts("");

    trav(s, ans){
      cout << s << endl;
    }

  } else{
    puts("-1");
  }
}
