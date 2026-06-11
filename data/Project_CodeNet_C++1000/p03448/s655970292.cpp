#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll A = 0,B = 0,C = 0,X = 0,ans = 0;
  cin >> A >> B >> C >> X;
  rep(i,A+1){
    rep(j,B+1){
      rep(k,C+1){
        if(500*i+100*j+50*k == X){
          ans++;
        }
      }
    }
  }
  cout << ans;
}