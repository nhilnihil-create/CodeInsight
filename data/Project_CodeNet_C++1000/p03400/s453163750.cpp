#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D,X;
  cin >> N >> D >> X;
  int ans = 0;
  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    int j = 1;
    while(j<=D){
      ans++;
      j+= a;
    }
  }
  cout << ans+X << endl;
}