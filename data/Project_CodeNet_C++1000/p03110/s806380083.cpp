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

  int n;
  cin >> n;

  double ans = 0;
  REP(i, 0, n){
      double x;
      string str;
      cin >> x >> str;
      if(str == "JPY")
        ans += x;
      else
        ans += x * 380000;
  }

  cout << fixed << setprecision(6) << ans <<endl;

  return 0;
}
