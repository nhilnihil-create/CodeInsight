#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int64_t k,a,b;
  cin >> k >> a >> b;
  if(k <= a || a+2 >= b){
    cout << k+1;
  }else{
    if((k-a+1) % 2 == 0){
      cout << a+(b-a)*((k-(a-1))/2);
    }else{
      cout << 1+a+(b-a)*((k-a)/2) << endl;
    }
  }
}
      
      
      
    
      