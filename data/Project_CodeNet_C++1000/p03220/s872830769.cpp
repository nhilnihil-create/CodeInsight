#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,T,A;
  cin>>N>>T>>A;
  ll place=0;
  double value;
  for(ll i=0;i<N;i++) {
    double H;
    cin>>H;
    H=T-H*0.006;
    if(place==0) {
place=1;
    value=abs(A-H);
    }
    
    else if(abs(A-H)<value) {
value=abs(A-H);
      place=i+1;
    }
  }
  
  
  cout<<place<<endl;
}
    