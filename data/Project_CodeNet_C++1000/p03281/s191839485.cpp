#include<iostream>
using namespace std;

bool countdiv8(int i) {
  int j,count=0;
  
  for(j=1; j<=i; j++) {
    if(i%j==0) {
      count++;
    }
  }
  
  if(count == 8) return true;
  else return false;
}

int main() {
  int i,N,count=0;
  
  cin >> N;
  
  for(i=1;i<=N;i+=2) {
    if(countdiv8(i)) count++;
  }
  
  cout << count << endl;
  
  return 0;
}