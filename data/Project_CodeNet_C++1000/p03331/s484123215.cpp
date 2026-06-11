#include <bits/stdc++.h>
using namespace std;

int wa(int x){
  int count =x%10;
  while(x/10>0){
    x/=10;
    count+=x%10;
  }
  return count;
}

int main(){
  int N;
  cin >> N;
  int min=N;
  for(int i=1; i<N; i++){
    int A=i, B=N-i;
    if(min>wa(A)+wa(B))
      min=wa(A)+wa(B);
  }
  cout << min << endl;
}