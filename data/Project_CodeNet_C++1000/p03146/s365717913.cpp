#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin>>x;
  
  set<int> s;
  s.insert(x);
  
  int i=2;
  while(1){
    if(x%2==0) x=x/2;
    else x=3*x+1;
    if(s.find(x)!=s.end()) break;
    s.insert(x);
    i++;
  }
  
  cout<<i<<endl;
  
  return 0;
}