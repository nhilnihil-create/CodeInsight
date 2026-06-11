#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c,k;
  cin>>a>>b>>c>>k;
  long long t=0;
  long long m=0;
  if(k%2==0){
    t=k*a+(k-1)*(b+c);
    m=k*b+(k-1)*(a+c);
  }
  else{
    t=(k-1)*a+k*(b+c);
    m=(k-1)*b+k*(a+c);
  }
  if(abs(t-m)>1000000000000000000){
    cout<<"Unfair"<< endl;
  }
  else{
    cout<<t-m<< endl;
  }
}