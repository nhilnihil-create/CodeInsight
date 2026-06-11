#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int ans;
  if(N%2!=0){
    ans=2*N;
  }else{
    ans=N;
  }
  cout << ans << endl;
}