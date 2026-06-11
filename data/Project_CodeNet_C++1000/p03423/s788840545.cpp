#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int ans=0;
  while(N>=3){
    N-=3;
    ans++;
  }
  cout << ans <<endl;
}