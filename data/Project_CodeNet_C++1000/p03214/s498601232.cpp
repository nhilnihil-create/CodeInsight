#include <bits/stdc++.h>
using namespace std;

int main() {
  double N;
  cin>>N;
  vector<double> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
    }
  double m=0;
for(int i=0;i<N;i++){
  m+=a[i]/N;
}

double d=1234567890;
long ans=-1;
for(int i=0;i<N;i++){
  if(d>abs(a[i]-m)){
    d=abs(a[i]-m);
    ans=i;
  }
}
cout<<ans<<endl;
}
