#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi l(n);
  rep(i,n) cin >> l[i];
  sort(l.rbegin(),l.rend());
  int sum=0;
  rep(i,n-1) sum += l[i+1];
  if(l[0] < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}
