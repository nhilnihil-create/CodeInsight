#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, j, k, min=INT_MAX, A, B, C, X, count=0;
  
  cin >> A >> B >> C >> X;
  
  for(i=0; i<A+1; i++){
    for(j=0; j<B+1; j++){
      for(k=0; k<C+1; k++){
        if(i*500+j*100+k*50==X) count+=1;
      }
    }
  }
  
  cout << count;
}


