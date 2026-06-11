#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<int64_t> a(s.size()+1,0);
  vector<int64_t> b(s.size()+1,0);
  vector<int64_t> c(s.size()+1,0);
  int p=1000000007;
  int64_t x=1;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='A'){
      a[i+1]=(a[i]+x)%p;
      b[i+1]=b[i];
      c[i+1]=c[i];
    }
    if(s.at(i)=='B'){
      a[i+1]=a[i];
      b[i+1]=(b[i]+a[i])%p;
      c[i+1]=c[i];
    }
    if(s.at(i)=='C'){
      a[i+1]=a[i];
      b[i+1]=b[i];
      c[i+1]=(c[i]+b[i])%p;
    }
    if(s.at(i)=='?'){
      a[i+1]=(a[i]*3+x)%p;
      b[i+1]=(b[i]*3+a[i])%p;
      c[i+1]=(c[i]*3+b[i])%p;
      x=x*3%p;
    }
  }
  cout<<c[s.size()]<<endl;
}