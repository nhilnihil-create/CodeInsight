#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
  ll N, M;  cin >> N >> M;
  if(N >= M){cout << 0 << endl; return 0;}
  VL x(M); rep(i,0,M) cin >> x[i];
  sort(x.begin(), x.end());
  
  ll L = x[M-1] - x[0];
  VL l(M-1);
  rep(i,1,M){
    l[i-1] = x[i] - x[i-1];
    //cout << l[i-1] <<endl;
  }
  sort(l.rbegin(), l.rend());

  rep(i,0,N-1){
    L -= l[i];
  }
  cout << L << endl;
  return 0;
}