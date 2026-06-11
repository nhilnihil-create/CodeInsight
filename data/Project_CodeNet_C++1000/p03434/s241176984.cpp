#include<iostream>
using namespace std;

int main() {
  int N,i,j,max,tmp,sum=0;
  
  cin >> N;
  
  int a[N];
  
  for(i=0;i<N;i++) cin >> a[i];
  
  for(i=0;i<N;i++) {
    //max = a[i];
    for(j=i+1;j<N;j++) {
      if(a[i] < a[j]) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
  
  if(N%2 == 0) {
    for(i=0;i<N-1;i+=2) {
      sum += (a[i]-a[i+1]);
    }
  } else {
    for(i=0;i<N-2;i+=2) {
      sum += (a[i]-a[i+1]);
    }
    sum += a[N-1];
  }
  
  cout << sum << endl;;
  
  return 0;
}