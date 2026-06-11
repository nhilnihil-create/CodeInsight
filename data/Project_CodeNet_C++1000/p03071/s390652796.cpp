#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int a,b;
  cin >>a >>b;
  int ans=0;
  if(a>=b){ans+=a;a--;}else{ans+=b;b--;}
  if(a>=b){ans+=a;a--;}else{ans+=b;b--;}
  cout << ans << endl;
}