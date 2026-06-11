#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  vector<int> X,Y;
  rep(i,n){
    long long x;
    cin>>x;
    X.push_back(x);
    Y.push_back(x);
  }
  sort(X.begin(),X.end());
  long long ml=X[n/2-1],mr=X[n/2];
  //cout<<ml<<" "<<mr<<endl;
  rep(i,n){
    if(Y[i]<=ml) cout<<mr<<endl;
    else if(Y[i]>=mr) cout<<ml<<endl;
  }
  return 0;
}