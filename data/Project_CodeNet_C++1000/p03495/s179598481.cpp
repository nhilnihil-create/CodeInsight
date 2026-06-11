#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  int n,k;cin>>n>>k;
  int a;
  vector<int>v(200005);
  rep(i,n){
    cin>>a;
    v[a]++;
  }
  sort(all(v),greater<int>());
  cout<<n-accumulate(v.begin(),v.begin()+k,0)<<endl;
}