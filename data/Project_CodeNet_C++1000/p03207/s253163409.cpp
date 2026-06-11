#include <bits/stdc++.h>
using namespace std;

int main(void){
 
  int N,c=0;
  cin >> N;
  int data[N];
  
  for(int i=0;i<N;i++) cin >> data[i];
  
  sort(data,data+N);
  
  for(int i=0;i<N;i++){
      if(i != N-1) c+= data[i];
      if(i == N-1) c+= (data[i] / 2);
  }
  cout << c << endl;
}