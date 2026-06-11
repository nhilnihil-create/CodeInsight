#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
 
ll A,B,K;
  cin>>A>>B>>K;
  if(2*K>=B-A+1) {
while(A<=B) {
cout<<A<<endl;
  A++;
}
    return 0;
  }
  ll count=0;
  while(count<K) {
cout<<A<<endl;
    count++;
    A++;
  }
  
  count=0;
  B-=(K-1);
  while(count<K) {
    cout<<B<<endl;
    B++;
    count++;
  }
}

  
  
  

  
  
