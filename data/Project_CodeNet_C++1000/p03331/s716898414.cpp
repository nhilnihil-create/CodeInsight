#include <bits/stdc++.h>
using namespace std;

int keta(int i){
  int sum = 0;
  while(i>0){
    int n = i%10;
    sum += n;
    i /= 10;
  }
  return sum;
}
    

int main(){
  int N;
  cin >> N;
  
  int min = 100;
  
  for(int i=1; i<N;i++){
    int ketawa = keta(i) + keta(N-i);
    if(ketawa < min){
      min = ketawa;
    }
  }
  cout << min << endl;
  
  
}