#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int GCD(int a, int b){
  if(b==0){
    return a;
  }
  GCD(b, a%b);
}
  


int main(){
  int N, X;
  cin >> N >> X;
  int ans;
  cin >> ans;
  if(ans>=X) ans = ans - X;
  else ans = X - ans;
  rep(i,N-1){
    int x;
    cin >> x;
    if(x>=X) x = x - X;
    else x = X - x;
    ans = GCD(ans, x);
  }
  cout << ans << endl;
   
}
    


