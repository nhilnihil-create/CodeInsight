#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  rep(i,9){
    char c;
    cin>>c;
    if(i==0 || i==4 || i==8)
      cout<<c;
  }
  cout<<endl;
}