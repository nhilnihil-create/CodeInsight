#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;

  int count=s.size();

  int white = 0;
  rep(i,count){
    if(s.at(i)=='W')white++;
  }

  ll ans=0;
  ll move=0;
  
  rep(i,count){
    if(s.at(i)=='W'){
      ans += i-move;
      move++;
    }
  }
  
  cout << ans;
}