#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin>>N;
  vector<long> a(N);
  long as=0;
  for(int i=0;i<N;i++) cin>>a[i],as+=a[i];
  vector<long> b(N);
  long bs=0;
  for(int i=0;i<N;i++) cin>>b[i],bs+=b[i];
  long ms=bs-as;
  if(ms<0){
    cout<<"No"<<endl;
    return 0;
  }
  long am=0,bm=0;
  for(int i=0;i<N;i++){
    if(a[i]>b[i]) bm+=a[i]-b[i];
    else{
      long tmp=(b[i]-a[i])/2;
      am+=tmp;
      a[i]+=tmp*2;
      if(a[i]<b[i]) am++,bm++;
    }
  }
  //cout<<ms<<am<<bm<<endl;
  if(ms>=am) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  }
