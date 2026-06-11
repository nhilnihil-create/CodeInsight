#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n,p;
  cin >> n>>p;
  if(n==1){
    cout<<p<<endl;
  }
  else{
  vector<int>a(1000100);
  rep2(i,2,1000100){
    long w=p;
    while(w%i==0){
      w/=i;
      a.at(i)++;
    }
  }
  long ans=1;
  rep2(i,2,1000100){
    if(a.at(i)>=n){
      ans=i;
    }
  }
  
  cout<<ans<<endl;  
  }
}

