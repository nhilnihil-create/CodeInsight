#include<bits/stdc++.h>
using namespace std;
int main(){
  char x[60];
  int N, K;
  cin>>N>>K;
  for(int i = 0;i<N;i++){
    cin>>x[i];
    if(x[K-1] == 'A'){
      x[K-1] = 'a';
    }
     if(x[K-1] == 'B'){
      x[K-1] = 'b';
    }
     if(x[K-1] == 'C'){
      x[K-1] = 'c';
    }
  }
  for(int i = 0;i<N;i++){
  cout << x[i];
  }
}
  
  