#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(){
  
}
 
int main(){
  bool IsPrime[100001];
  for(int i=0; i<100001; i++){
    IsPrime[i] = true;
  }
  IsPrime[0] = false;
  IsPrime[1] = false;
  for(int i=0; i<100001; i++){
    if(IsPrime[i]){
      for(int j=2; i*j<100001; j++){
        IsPrime[i*j] = false;
      }
    }
  }
  int q;
  cin >> q;
  int s[100001] = {};
  for(int i=1; i<100001; i++){
    s[i] = s[i-1];
    if(IsPrime[i]){
      if(IsPrime[(i+1)/2]) s[i] = s[i-1] + 1;
    }
  }
  for(int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    cout << s[r]-s[l-1] << endl;
  }
  return 0;
}
