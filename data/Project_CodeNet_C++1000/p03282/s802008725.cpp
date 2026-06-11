#include <bits/stdc++.h>
// #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);i++)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {

  string s;cin >> s;
  int k;cin >> k;
  rep(i,k){
    if (s[i]!='1'){
      cout<<s[i]<<endl;
      return 0;
    }
  }
  cout<<1<<endl;  
}
