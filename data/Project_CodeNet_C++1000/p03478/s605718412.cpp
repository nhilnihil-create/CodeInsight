#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int cul(int i){
  int sum=0;
  while(i>0){
    sum+=i%10;
    i=i/10;
  }
  return sum;
}
int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int total=0;
  repi(i,1,n+1){
    int sum=cul(i);
    if(sum>=a&&sum<=b) total+=i;
  }
  cout<<total<<endl;
}