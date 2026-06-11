#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
bool is_prime(int n) {
  if(n==1) return false;
  else if (n == 2) return true;
  else if (n%2 == 0) return false;
  for(int d = 3; d*d <= n; d += 2) {
    if( n % d == 0 ) return false;
  }
  return true;
}
int main()
{
    int Q;
    cin >> Q;
    int l = INT_MAX, r = 0;
    vector<P> A;
    rep(i, Q)
    {
        int a, b;
        cin >> a >> b;
        A.emplace_back(a, b);
        chmin(l, a);
        chmax(r, b);
    }
    //cout << l << "<" << r << endl;
    int l2 = (l+1)/2;
    int r2 = (r+1)/2;
    int n = r-l+1;
    vector<int> B1(n), B2(n);
    // is_prime(3);
    // return 0;
    B1[0] = 0;//(is_prime(l) && is_prime((l+1)/2) ? 1 : 0);
    //return 0;
    //B2[0] = (is_prime((l+1)/2) ? 1 : 0);
    rep(i, 1+n)
    {
        B1[i] = B1[i-1] + (is_prime(l+i-1)&&is_prime((l+i)/2) ? 1 : 0);
        //B2[i] = B2[i-1] + (is_prime((l+i+1)/2) ? 1 : 0);
    }
    rep(i, Q)
    {
        int a = A[i].first-l;
        int b = A[i].second-l+1;
        int ans = B1[b]-B1[a];
        cout << ans << endl;
    }


    return 0;
}