#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, n) ;for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) ;for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF (922337203685477587+1)
#define sosuu 1000000007

string keyence="keyence";

int main() {
  lli N;
  cin >> N;
  lli sumA=0,sumB=0;
  vector<lli> A(N);
  vector<lli> B(N);
  int ans=0;
  lli lack=0;
  rep(i, N){
  cin >> A[i];
    sumA+=A[i];
  }
  rep(i, N){
  cin >> B[i];
    sumB+=B[i];
  }
  if(sumA<sumB){
    cout << -1 << endl;
    return 0;
  }
  
  vector<lli> defference(N);
  rep(i, N)
  {
  defference[i]=A[i]-B[i];
    if(defference[i]<0){
      lack-=defference[i];
      ans++;
    }
  }
  sort(ALL(defference));
  reverse(ALL(defference));
  rep(i, N){if(lack<=0){
  break;
  }
  ans++;
    lack-=defference[i];
  
  }
  cout << ans << endl;
}