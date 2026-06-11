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
  int N;
  cin >> N;
  if(N==1)
    cout << "Hello World" << endl;
  else{
    int a;
  N=0;
  cin >>a;
  N+=a;
  cin >>a;
  N+=a;
  cout << N << endl;
  }
}