#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vi v;
  int cnt0 = 0;
  int cnt1 = 0;
  rep(i,n) {
    if(cnt1>0 && s[i]=='0') {
      v.push_back(cnt1);
      cnt1 = 0;
      cnt0 = 1;
    }
    else if(cnt0>0 && s[i]=='1') {
      v.push_back(cnt0);
      cnt0 = 0;
      cnt1 = 1;
    }
    else if(s[i]=='1') cnt1++;
    else cnt0++;
  }
  if(cnt0>0) v.push_back(cnt0);
  else v.push_back(cnt1);
  if(s[0]=='1') {
    int ans = 0;
    int tmp = 0;
    rep(i,2*k+1) {
      if(i>=v.size()) break;
      tmp += v[i];
    }
    ans = tmp;
    rep(i,v.size()-2*k-1) {
      if(i<0 || 2*k+1+i >= v.size()) break;
      tmp -= v[i];
      tmp -= v[i+1];
      tmp += v[2*k+1+i];
      if(2*k+2+i < v.size()) tmp += v[2*k+2+i];
      ans = max(ans,tmp);
      i++;
    }
    cout << ans << endl;
    return 0;
  }
  else {
    int ans = 0;
    int tmp = 0;
    rep(i,2*k) {
      if(i>=v.size()) break;
      tmp += v[i];
    }
    ans = tmp;
    rep(i,v.size()-2*k) {
      if(i==0) {
        tmp -= v[i];
        if(2*k+i < v.size()) tmp += v[2*k+i];
        if(2*k+i+1 < v.size()) tmp += v[2*k+i+1];
        ans = max(ans,tmp);
        continue;
      }
      if(i<0 || 2*k+1+i >= v.size()) break;
      if(i==0) {
        tmp -= v[i];
        tmp += v[2*k+i];
        tmp += v[2*k+i+1];
        ans = max(ans,tmp);
        continue;
      }
      tmp -= v[i];
      tmp -= v[i+1];
      tmp += v[2*k+1+i];
      if(2*k+2+i < v.size()) tmp += v[2*k+2+i];
      ans = max(ans,tmp);
      i++;
    }
    cout << ans << endl;
    return 0;
  }
}