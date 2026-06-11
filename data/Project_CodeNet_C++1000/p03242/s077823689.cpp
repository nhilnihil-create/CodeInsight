#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  string n;
  cin>>n;
  rep(i,n.size()){
    if(n[i]=='1') cout<<"9";
    else if(n[i]=='9') cout<<"1";
    else cout<<n[i];
  }
  cout<<endl;
  return 0;
}
