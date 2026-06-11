#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int main(void){
  vector<int> a(3),b(3);

  rep(i,3){
    cin >> a.at(i);
    cin >> b.at(i);
  }
  map<int,int> p;
  rep(i,3){
    p[a.at(i)]++;
    p[b.at(i)]++;
  }

  for(auto x : p){
    if(x.second>=3){
      cout << "NO" << endl;
      return 0;
    }
  }    
  cout << "YES" << endl;
  
  return 0;
}
