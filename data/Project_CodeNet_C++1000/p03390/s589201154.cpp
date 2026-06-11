#include<bits/stdc++.h>
using namespace std;
int main(void){
  int q; cin>>q;
  vector<long long> a(q),b(q);
  for(int i=0; i<q; ++i) cin>>a[i]>>b[i];
  for(int i=0; i<q; ++i){
    long long ab=a[i]*b[i]-1,sqr=sqrtl(ab),sq=sqr*2;
    if(a[i]==1&&b[i]==1) cout<<0<<endl;
    else if(a[i]==b[i]) cout<<sq<<endl;
    else if(sqr*sqr!=ab&&sqr*(sqr+1)<=ab) cout<<sq-1<<endl;
    else cout<<sq-2<<endl;
  }
  return 0;
}
