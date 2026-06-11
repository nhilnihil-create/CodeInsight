#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for(int i=0;i<N;i++) {
    cin >> d.at(i);
  }
  
  int premax=0, k=0;
  
  for(int i=0;i<N;i++) {
    
  int max=0, maxnum=0;      

 	for(int i=0;i<N;i++) {
  	  if(d.at(i)>max) {
        max=d.at(i);
        maxnum=i;
      }
  	}
    
    if(max!=premax) k++;
    
    premax=max;
    d.at(maxnum)=0;

  }
  
  cout << k << endl;
  
}