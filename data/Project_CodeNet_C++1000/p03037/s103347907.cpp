#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N=0,M=0;
  cin >> N >> M;
  vector<ll>A(M);
  vector<ll>B(M);
  rep(i,M){
    cin >> A[i];
    cin >> B[i];
  }
  sort(B.begin(), B.end()); //小さい順
  sort(A.begin(), A.end()); //小さい順
  reverse(A.begin(), A.end());
  if(B[0] >= A[0]){
    cout << B[0]-A[0]+1;
  }
  else{
    cout << "0";
  }
}