#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(){
  int N;
  ll X;
  cin >> N >> X;
  ll x[N+1];
  for(int i=0;i<N;i++){
    cin >> x[i];
  }
  x[N]=X;
  sort(x,x+N+1);
  ll p = x[1]-x[0];
  for(int j=1;j<N;j++){
    ll sub = x[j+1]-x[j];
    p = gcd(sub,p);
  }
  cout << p << endl;
}
