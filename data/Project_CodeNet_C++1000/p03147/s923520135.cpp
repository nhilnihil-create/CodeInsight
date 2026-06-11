#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
   int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int ans=a.at(0),p=ans;
  rep(i,n-1){
    if(p<=a.at(i+1)){
      ans+=a.at(i+1)-p;
      p=a.at(i+1);
    }else{
      p=a.at(i+1);
    }
  }
  cout << ans;
}