#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
int n,t=24,c[2],d[50];

int main() {
  cin>>n;
  rep(i,n)cin>>d[i];
  sort(d,d+n);
  rep(i,n) {
    t=min(t,d[i]-c[i&1]);
    c[i&1]=d[i];
  }
  cout<<min(t,24-c[0]-c[1])<<endl;
}
