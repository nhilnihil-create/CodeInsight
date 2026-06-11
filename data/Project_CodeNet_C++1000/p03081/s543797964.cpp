// clang-format

#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;

using lli = long long int;
int sim(int cur, long long N, long long Q, std::string s, std::vector<char> t,
           std::vector<char> d) {
  rep(i, Q){
    if(s[cur]==t[i]){
      if(d[i]=='L')cur--;
      else cur++;
    }
    if(cur==-1) return 1;
    else if(cur==N)return 2;
  }
  return 0;
}

void solve(long long N, long long Q, std::string s, std::vector<char> t,
           std::vector<char> d) {
  lli left = -1, right = N;
  while(right-left>1){
    lli mid = (left+right)/2;
    lli p = sim(mid, N, Q, s, t, d);
    if(p==1){
      left = mid;
    }else {
      right = mid;
    }
  }
  if(left==N-1){
    cout << 0 << endl;
    return;
  }
  lli tmp_l = right;
  left = -1, right = N;
  while(right-left>1){
    lli mid = (left+right)/2;
    lli p = sim(mid, N, Q, s, t, d);
    if(p==2){
      right = mid;
    }else {
      left = mid;
    }
  }
  lli tmp_r = left;
  if(right==0){
    cout << 0 << endl;
    return;
  }

  cout << tmp_r - tmp_l +1 << endl;

}


int main() {
  int a;
  long long N;
  scanf("%lld", &N);
  long long Q;
  scanf("%lld", &Q);
  std::string s;
  std::cin >> s;
  std::vector<char> t(Q);
  std::vector<char> d(Q);
  for (int i = 0; i < Q; i++) {
    std::cin >> t[i];
    std::cin >> d[i];
  }
  solve(N, Q, s, std::move(t), std::move(d));
  return 0;
}
