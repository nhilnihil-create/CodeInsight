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

int main() {
  vector<int> A(4);
  rep(i, 4){
  cin >> A[i];
  }
  sort(ALL(A));
  if(A[0]==1&&A[1]==4){
    if(A[2]==7&&A[3]==9){
    cout << "YES" << endl;
      return 0;
    }
  }
  cout <<"NO" << endl;
}