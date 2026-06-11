#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, j, k, N, A, B, x, y, count=0, min=INT_MAX, sum;
  
  cin >> N;
  
  
  rep(i,N/2+1){
    x=y=0;
    A=i+1;
    B=N-i-1;

    for(;A!=0;){
        
      x+=A%10;
      A/=10;
    }
    for(;B!=0;){
      y+=B%10;
      B/=10;
    }
      
    if(x+y<min) min=x+y;
  }
    
    cout << min;
}
  




