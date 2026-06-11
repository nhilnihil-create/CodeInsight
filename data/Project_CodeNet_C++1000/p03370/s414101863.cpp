#include <bits/stdc++.h>
using namespace std;

int main(){

int N,X;
  cin >> N >> X;
  int min=10000;
  int m[N];
  int count=N;
  for(int i=0;i<N;i++){
  cin >> m[i];
   int t= m[i];
    X-=t;
    if(min>t)min = t;
  
  }
  cout << N + X/min << endl;

}