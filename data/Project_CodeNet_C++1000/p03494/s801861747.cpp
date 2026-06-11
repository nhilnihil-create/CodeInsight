#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a[200];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  int flag = 1;
  int count = 0;
  
  while(flag == 1){
    for(int i = 0;i < N;i++) {
      if(a[i] % 2 == 1){
        flag = 0;
        break;
        }
    }
    if(flag == 0) break;
    for(int i = 0; i < N; i++) {
      a[i] /= 2;
    }
    count++;  
  }
  cout << count << endl;
    
}