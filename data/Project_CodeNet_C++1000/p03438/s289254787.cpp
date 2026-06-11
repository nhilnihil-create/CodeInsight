#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin>>n;
  vector<long>a(n),b(n);
  rep(i,n){
    cin>>a.at(i);
  }
  rep(i,n){
    cin>>b.at(i);
  }
  long ta=0;
  long tb=0;
  rep(i,n){
    ta+=a.at(i);
    tb+=b.at(i);
  }
  bool ex=true;
  if(ta-tb>0){
    ex=false;
  }
  if(ex){
    long di=tb-ta;
    long di2=0;
    long di3=0;
    rep(i,n){
      if(a.at(i)-b.at(i)>0){
        di2+=a.at(i)-b.at(i);
      }
      else{
        di3+=(b.at(i)-a.at(i)+1)/2;
      }
    }
    if(di2>di||di3>di){
      ex=false;
    }
  }
  if(ex){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}