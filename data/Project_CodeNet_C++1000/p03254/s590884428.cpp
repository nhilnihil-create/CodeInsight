#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,x;
  cin >> N >> x;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  int i=0;
  for(i;i<N-1;i++){
    if(A.at(i)<=x){
      x-=A.at(i);      
    }else{
      break;
    }
  }
  if(x==A.at(N-1)){
    i++;
  }
  
  cout << i << endl;
}

