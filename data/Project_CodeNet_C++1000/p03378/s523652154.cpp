#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N, M, X, Lcost = 0, Rcost = 0;
  cin >> N >> M >> X;
  
  for (int i = 0; i < M; i++){
    int a;
    cin >> a;
    
    if (a < X){
      Lcost++;
    }
    else{
      Rcost++;
    }
  }
  
  int ans = min(Lcost, Rcost);
  cout << ans << endl;
}