#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <numeric>
#define rep(i,s,n) for (int i = s; i < n; ++i)
#define drep(i,s,n) for (int i = n; i >= s; --i)
#define all(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define print(x) cout<<(x)<<endl
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
   if (a%b == 0) return(b);
   else          return(gcd(b, a%b));
}
int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
void printvv(vector<vector<auto>> vv, int n)
{
  cout << '[' << endl;
  rep(q, 0, n)
  {
    cout << '[';
    rep(p, 0, n)
    {
      cout << vv.at(q).at(p) << ',';
    }
    cout << ']' << endl;
  }
  cout << ']' << endl;
}

void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

//------------------------------------------------------------
void solve() {
  int N, a,b;
  cin >> N >> a >> b;

  if ((b-a-1)%2==0) print("Borys");
  else print("Alice");

  return;
}
