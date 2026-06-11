#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;
void QA(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
  return;
}

int main() {
  int a,b; cin>>a>>b;
  QA(a%2==1&&b%2==1);
}

