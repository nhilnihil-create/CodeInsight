#include <bits/stdc++.h>
#define pb push_back
#define vt vector
#define ll long long
using namespace std;

const int INF = 1e9 +5;
const ll LLINF = 1e18 +5;

int i4[4] = {1,0,-1,0};
int j4[4] = {0,1,0,-1};


void solve()
{
	int a,b;
	cin >> a >> b;
    cout << (((a*b)&1)? "Odd":"Even") << endl;


}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();

  return 0;
}
