#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main(){
  int n, q; string s;
  cin >> n >> q >> s;
  vector<int> cnt(n,0);
  for(int i = 1; i < n; i++){
    if(s[i-1] == 'A' && s[i] == 'C'){
      cnt[i] = cnt[i-1]+1;
    }else{
      cnt[i] = cnt[i-1];
    }
  }
  for(int i = 0; i < q; i++){
    int l,r; cin >> l >> r;
    l--; r--;
    int now = cnt[r] - cnt[l];
    cout << now << endl;
  }
  return 0;
}
