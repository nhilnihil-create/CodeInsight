#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<int>a(3),b(3);
  vector<int> vec(4);
  rep(i,3)cin>>a[i]>>b[i];
  rep(i,3){
    vec[a[i]-1]++;vec[b[i]-1]++;
  }
  rep(i,4){
    if(vec[i]==3){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}