#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  vector<int> a(4);
  rep(i,4) cin >> a[i];
  sort(all(a));
  if (a[0]==1 && a[1]==4 && a[2]==7 && a[3]==9) cout << "YES" << endl;
  else cout << "NO" << endl;
}
