#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main(){
  ll a,b,c,n;
  cin >> n ;
  if(n==0){
    cout<<2<<endl;
  }else if(n==1){
    cout<<1<<endl;
  }else{
    b=1,c=2;
    for(int i=0;i<n-1;i++){
      a=b+c;
      c=b;
      b=a;
    }
    cout<<b<<endl;
  }
   
}