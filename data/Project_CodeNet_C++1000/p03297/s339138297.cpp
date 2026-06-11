#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll MOD=1e9+7;

int main(){
  int T;cin>>T;
  for (int i=0;i<T;++i){
    ll A, B, C, D;cin>>A>>B>>C>>D;
    if(A<B) {cout << "No" << endl;}
    else if(B>D){cout << "No" << endl;}
    else if(C>=B){cout << "Yes" << endl;}
    else{
      ll g=__gcd(D, B);
      if(B-g+A%g>C){cout << "No"<< endl;}
      else{cout << "Yes" << endl;}
    }
    
  }
  return 0;
}