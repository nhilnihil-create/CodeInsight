#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  int N, M;
  cin >> N >> M;
  int tot=1900*M+100*(N-M);
  cout << tot*pow(2,M) << endl;

  return 0;
}
