#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  string s;
  cin >> n >> s;

  //a=97
  vector<int> all(26);
  int ans=0;

  rep(i,n){
    int j = s.at(i)-97;
    all.at(j)++;
  }
  
  rep(i,n){
    vector<int> x(26);
    rep(j,i){
      int l=s.at(j)-97;
      x.at(l)++;
    }
    
    int count=0;
    rep(k,26){
      if(x.at(k)&&(all.at(k)-x.at(k))) count++;
    }

    ans = max(ans, count);
  }

  cout << ans;
}