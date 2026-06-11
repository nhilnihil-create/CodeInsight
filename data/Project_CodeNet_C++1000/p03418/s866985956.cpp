#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n,k;
  cin >> n >> k;
  long ans = 0;
  for(int b=k+1;b<=n;b++){
    long tmp = (n+1)/b;
    ans += (b-k)*tmp;
    int tmp1 = n - (tmp)*b - k + 1;
    ans += max(tmp1,0);
    if(k == 0) ans--;
  }
  cout << ans << endl;
}