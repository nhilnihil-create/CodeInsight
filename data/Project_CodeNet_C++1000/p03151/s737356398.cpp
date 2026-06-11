#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  int n;
  cin>>n;
  bool ex=true;
  long at=0;
  long bt=0;
  vector<int>a(n),b(n);
  rep(i,n){
    cin>>a.at(i);
  }
  rep(i,n){
    cin>>b.at(i);
  }
  rep(i,n){
    at+=a.at(i);
    bt+=b.at(i);
    if(a.at(i)<b.at(i)){
      ex=false;
    }
  }
  if(at<bt){
    cout<<-1<<endl;
  }
  else if(ex){
    cout<<0<<endl;
  }
  else{
    int co=0;
    long to=0;
    vector<int>c(n);
    rep(i,n){
      c.at(i)=a.at(i)-b.at(i);
      if(a.at(i)<b.at(i)){
        co++;
        to+=b.at(i)-a.at(i);
      }
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int k=0;
    while(to>0){
      to-=c.at(k);
      k++;
      co++;
    }
    cout<<co<<endl;
  }
}