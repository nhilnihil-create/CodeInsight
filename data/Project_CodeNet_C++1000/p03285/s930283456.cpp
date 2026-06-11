#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(4*i+7*j == N) {
        ans=1;
      }
    }
  }
  if(ans==1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}