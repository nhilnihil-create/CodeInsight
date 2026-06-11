#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  int n,m;
  cin >> n >> m;
  if(m==1 || n>=m){
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(m);
  for(int i=0;i<m;i++){
    cin >> x.at(i);
  }
  sort(x.begin(),x.end());
  int max=x.at(m-1)-x.at(0);
  if(n==1){
    cout << max << endl;
    return 0;
  }
  vector<int> sa(m-1);
  for(int j=0;j<m-1;j++){
    sa.at(j)=x.at(j+1)-x.at(j);
  }
  sort(sa.begin(),sa.end());
  reverse(sa.begin(),sa.end());
  int sum=0;
  for(int i=0;i<n-1;i++){
    sum+=sa.at(i);
  }
  cout << max-sum << endl;
}