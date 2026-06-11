#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N ;
  bool possible = false;

  for (int i=0;i<=N/4;i++){
    for (int j=0;j<=N/7;j++){
      if (4*i+7*j == N) possible = true;
      else if(4*i+7*j>N) break;
    }
  }
  cout << (possible ? "Yes" : "No") << endl;

}

  
  