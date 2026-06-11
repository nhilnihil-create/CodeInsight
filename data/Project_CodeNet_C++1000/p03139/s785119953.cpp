#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,a,b;cin>>n>>a>>b;
  cout<<min(a,b)<<" "<<max(0, a+b-n)<<endl;
  
}
