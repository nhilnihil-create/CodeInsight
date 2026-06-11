#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  long n;
  cin >> n;
  vector<long>a(n);
  rep(i,n){
    cin>>a.at(i);
    a.at(i)-=i+1;
  }
  sort(a.begin(),a.end());
  long now=0;
  rep2(i,1,n){
    a.at(i)-=a.at(0);
    now+=a.at(i);
  }
  a.at(0)=0;
  rep2(i,1,n){
    if(a.at(i)-a.at(i-1)!=0){
      if(i<n-i){
        now-=(a.at(i)-a.at(i-1))*(n-2*i);
      }
      else{
        break;
      }
    }
  }
  cout<<now<<endl;
}