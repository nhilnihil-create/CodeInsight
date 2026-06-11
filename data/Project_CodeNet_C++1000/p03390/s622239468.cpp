#include<bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin>>q;
  for(int _=0;_<q;_++){
    int64_t a,b;
    cin>>a>>b;
    if(a==1&&b==1){
      cout<<0<<endl;
      continue;
    }
    int64_t l=0;
    int64_t r=max(a,b);
    int64_t h;
    while(r-l>1){
      h=(l+r)/2;
      if(h*h>=a*b)
        r=h;
      else
        l=h;
    }
    cout<<l*2-(min(a,b)<=l?1:0)-((a*b-1)/l==l?1:0)<<endl;
  }
}