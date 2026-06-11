#include <bits/stdc++.h>
using namespace std;

int count(int x, int X){
  int sumX=0, sumY=0;
  int y=X-x;
  while(x>0){
    sumX+=x%10;
    x/=10;
  }
  while (y>0){
    sumY+=y%10;
    y/=10;
  }
  return sumX+sumY;
}
  
int main(){
  int N;
  cin >> N;
  int Min=54;
  for (int i=1; i<N; i++){
      Min=min(Min, count(i,N));
  }
  cout << Min << endl;
}