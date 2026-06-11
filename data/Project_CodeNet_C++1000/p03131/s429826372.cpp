#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long k,a,b,c;
  cin>>k>>a>>b;
  c=1;
  if(a>=b){
    cout<<k+1<<endl;
  }
  else {
    if(k<a+1){
      cout<<k+1<<endl;
    }
    else if(b-a==1){
      cout<<k+1<<endl;
    }
    else{
       if(k>=a-c+2){
          k-=(a-c+2);
          c=b;
        }
        while(k>1){
          c+=(b-a);
          k-=2;
        }
  if(k==1){
    c++;
    k--;
  }
      cout<<c<<endl;
    }
}
}