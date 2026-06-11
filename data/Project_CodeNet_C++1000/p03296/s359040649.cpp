#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n; 
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  int ans=0;
  rep(i,n-1){
    if(a.at(i)==a.at(i+1)){
      ans++;
      a.at(i+1)=-1;
    }
  } 
  cout<<ans<<endl;
}