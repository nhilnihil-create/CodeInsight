#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int N,i,count=1;
  
  cin >> N;
  int d[N];
  
  for(i=0;i<N;i++) cin >> d[i];
  
  sort(d,d+N);
  
  for(i=0;i<N-1;i++) {
    if(d[i] != d[i+1]) count++;
  }
  
  cout << count << endl;
  
  return 0;
}