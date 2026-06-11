#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int MARCH(vector<string> vec, int cnt){
  int M=0, A=0, R=0, C=0, H=0;
  rep(i,(int)vec.size()){
    if (vec.at(i).at(0) == 'M') M++;
    if (vec.at(i).at(0) == 'A') A++;
    if (vec.at(i).at(0) == 'R') R++;
    if (vec.at(i).at(0) == 'C') C++;
    if (vec.at(i).at(0) == 'H') H++;
  }
  if (M > 0) cnt++;
  if (A > 0) cnt++;
  if (R > 0) cnt++;
  if (C > 0) cnt++;
  if (H > 0) cnt++;
  return cnt;
}

int combination(int n,int k){//組み合わせ
  double ans = 1;
  if (k == 1){
    return n / k;
  }
  ans = (double)n / k * combination(n-1, k-1);
  return ans;
}

int main(){
  int n;
  cin >> n;
  string s = "MARCH";
  vi c(5);
  rep(i,n){
    string t;
    cin >> t;
    rep(j,5){
      if (t.at(0) == s.at(j)){
        c.at(j)++;
      }
    }
  }
  ll ans = 0;
  rep(i,5)REP(j,i+1,5)REP(k,j+1,5){
    ans += 1LL * c.at(i) * c.at(j) * c.at(k);
  }
  cout << ans << endl;
  return 0;
}
