#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n,m;
  cin>>n>>m;
  if(n%m!=0){
    cout<<1<<endl;
  }
  else{
    cout<<0<<endl;
  }
}