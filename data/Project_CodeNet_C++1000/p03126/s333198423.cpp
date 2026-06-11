#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define REP(i, a, n) for(int i=a; i<n; ++i)
#define pb push_back
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double PI = 3.141592653589793238460;
const ll mod = 1e9 + 7;

void FAST(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main(){
  FAST();

  int n, m;
  cin >> n >> m;
  vector<int> bitmask(n, 0);       // (1)each element for each person. (2)int because m <= 30, so will fit in an int.

  REP(i, 0, n){
      int k;
      cin >> k;
      REP(j, 0, k){
          int a;
          cin >> a;
          bitmask[i] |= (1<<a);   //bitmasking in 1-index
      }
  }

  int x = bitmask[0];
  REP(i, 1, n)
      x &= bitmask[i];

  cout << __builtin_popcount(x) << endl;



  return 0;
}
