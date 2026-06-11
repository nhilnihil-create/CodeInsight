#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;
  
  int n=s.size();

  string k = "keyence";

  int mae=0, ushiro=0;

  rep(i,7){
    if(s.at(i)==k.at(i))mae++;
    else break;
  }
  rep(i,7){
    if(s.at(n-1-i)==k.at(6-i))ushiro++;
    else break;
  }
  if(mae+ushiro>=7) cout << "YES";
  else cout << "NO";
}