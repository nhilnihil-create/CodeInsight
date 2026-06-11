#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,count=0;
  cin >> N >> K;
  for(int i=1;i<N+1;i+=2){
    count++;
  }
  if(count>=K){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}