#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s,t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();

  vector<int> sl(n);
  vector<int> tl(m);

  rep(i,n) sl.at(i) = s.at(i);
  rep(i,m) tl.at(i) = t.at(i);

  sort(sl.begin(), sl.end());
  sort(tl.rbegin(), tl.rend());

  //bool ans=true;
  if(n<m){
    rep(i,n){
      if(sl.at(i)<tl.at(i)) {cout << "Yes"; return 0;}
      else if(sl.at(i)>tl.at(i)){cout << "No"; return 0;}
    }
    cout << "Yes";
    return 0;
  }else if(n>=m){
    rep(i,m){
      if(sl.at(i)<tl.at(i)) {cout << "Yes"; return 0;}
      else if(sl.at(i)>tl.at(i)){cout << "No"; return 0;}
    }
    cout << "No";
    return 0;
  }
}