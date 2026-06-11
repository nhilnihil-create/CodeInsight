#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  int n;
  string s;
  cin>>n>>s;
  /////////
  
  int ans=0;
  
  rep(i,n){
    map<char,int> x,y;
    int cnt=0;
    for(int j=0;j<=i;j++){
    x[s[j]]++;
    }
    for(int j=i+1;j<n;j++){
      y[s[j]]++;
    }
    for(auto v:x){
     if(y.count(v.first)){
      cnt++; 
     }
    }
    //cout<<cnt<<endl;
    ans=max(ans,cnt);
    
  }
  cout<<ans<<endl;
}