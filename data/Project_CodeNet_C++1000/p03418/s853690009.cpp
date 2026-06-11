#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, k;
  cin >> n >>k;
  ll ans=0;
  if(k==0){
    cout << (ll)n*n << endl;
    return 0;
  }
  for(int b=k+1; b<=n; b++){
    ans+=n/b*(b-k);
    ans+=max(n%b-k+1, 0);
  }
  cout << ans << endl;
  return 0;
}
