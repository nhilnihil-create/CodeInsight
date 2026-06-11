#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  string s;
  cin >> n>>s;
  vector<int> a(n);
  int k=0;
  rep(i,n){
    if(s.at(i)=='E'){
      k++;
      a.at(i)=k;
    }else{
      a.at(i)=k;
    }
  }
  int ans=1e7;  
  ans=min(ans,a.at(n-1)-a.at(0));
  for(int i=1;i<n;i++){
    int mini;
    mini=(a.at(n-1)-a.at(i))+i-a.at(i-1);
    ans=min(ans,mini);
  }
  cout << ans;
}
    