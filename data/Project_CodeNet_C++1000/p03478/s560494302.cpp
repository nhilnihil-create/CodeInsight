#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;



int f(int n){
  int sum =0;
  while(n>0){
    sum +=n%10;
    n/=10;
  }
  return sum;
}
  
  
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int k=0;
  rep(i,n+1){
    int sum =f(i);
    if(a <=sum && sum <=b){
      k+=i;
    }
  }
  cout << k << endl; 
  
}