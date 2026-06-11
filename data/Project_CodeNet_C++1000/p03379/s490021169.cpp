#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  int n;cin>>n;
  int x[n],y[n];rep(i,n)cin>>x[i],y[i]=x[i];
  sort(x,x+n);
  int l=x[n/2-1],r=x[n/2];
  rep(i,n){
    cout<<(y[i]<r?r:l)<<endl;
  }
}