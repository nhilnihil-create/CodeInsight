#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

/*
9 -> ok
10 -> out
11 -> out
10^12 -> out

n
a1
..
an

n<100000
ai<1000000000

out: first, second
*/
typedef long long int ll;


int main(){
  ll n, p;
  cin >> n >> p;
  if(n == 1){
    cout << p << endl;
    return 0;
  }

  

  ll ans = 1;
  for(ll i = 2; i <= sqrt(p); i++){
    int cnt = 0;
    while(p % i == 0){
      p /= i;
      cnt++;
      if(cnt >= n){
        ans *= i;
        cnt = 0;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
