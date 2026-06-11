#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  int res=0;
  vector<int> mo={-1,31,30,31,30,31,30,31,31,30,31,30,31};
  for (int i=1; i<=a; i++) {
    for (int j=1; j<=(i<a?mo[i]:b); j++) {
      res+=(i==j);
    }
  }
  cout<<res<<endl;
  return 0;
}