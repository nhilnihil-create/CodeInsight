#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b,c,d,e,k; cin>>a>>b>>c>>d>>e>>k;
  vector<int> vec = {b-a,c-a,d-a,e-a,c-b,d-b,e-b,d-c,e-c,e-d};
  sort(vec.begin(),vec.end());
  if(vec[9] <= k) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}
