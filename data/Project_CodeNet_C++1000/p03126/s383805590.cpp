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

  int x = 0;
  REP(i, 0, n){
      int k;
      cin >> k;
      int bitmask = 0;
      REP(j, 0, k){
          int a;
          cin >> a;
          bitmask |= (1<<a);   //bitmasking in 1-index
      }
      x = (i == 0) ? bitmask : (x & bitmask);
  }

  cout << __builtin_popcount(x) << endl;



  return 0;
}
