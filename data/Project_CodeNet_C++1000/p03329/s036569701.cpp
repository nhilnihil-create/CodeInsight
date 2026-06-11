#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
  vector<int>a(100100);
  rep(i,6){
    a[i]=i;
  }
  rep2(i,6,9){
    a[i]=i-5;
  }
  rep2(i,9,100100){
    int d=1;
    while(d*6<=i){
      d*=6;
    }
    int b=1;
    while(b*9<=i){
      b*=9;
    }
    a[i]=min({a[i-1]+1,a[i-d]+1,a[i-b]+1});
  }
  
  cout<<a[n]<<endl;
}