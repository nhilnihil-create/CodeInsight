#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  int SumPrice=0,MaxPrice=0;
  rep(i,n){
    int p;
    cin>>p;
    SumPrice+=p;
    MaxPrice=max(MaxPrice,p);
  }
  cout<<SumPrice-MaxPrice/2<<endl;
  return 0;
}
