#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int K;
  cin >> K;
  vector<ll> A(K,0);
  for(int i=0;i<K;i++){
    cin >> A[K-1-i];
  }
  ll U=2,L=2;
  for(int i=0;i<K;i++){
    // U <= A[i]*S
    // A[i]*T <= L
    ll S = U/A[i];
    if(S*A[i]<U){
      S ++;
    }
    ll T = L/A[i];
    if(T<S){
      cout << -1 << endl;
      return 0;
    }else{
      U = S*A[i];
      L = (T+1)*A[i] -1;
    }
    //cout << U << " " << L << endl;
  }
  cout << U << " " << L << endl;
}