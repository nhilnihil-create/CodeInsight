#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
#define P pair<int, int>
#define ll long long
const int MOD = 1000000007;
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int main(){
  int a[3];
  rep(i, 3)
    cin >> a[i];
  sort(a, a+3);
  int ans = 2*a[2] - a[1] - a[0];
  if(ans%2==1)
    ans += 3;
  cout << ans/2 << endl;
}
