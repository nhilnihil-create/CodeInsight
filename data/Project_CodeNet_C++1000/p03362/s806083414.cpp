#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 55556;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > lp(MAXN, 0), primes;
  for(int i = 2; i < MAXN; i++){
    if(lp[i] == 0){
      lp[i] = i;
      primes.push_back(i);
    }
    for(int j = 0; j < primes.size() && primes[j] <= i && i * primes[j] < MAXN; j++){
      lp[i * primes[j]] = primes[j];
    }
  }

  ll cnt = 0;
  for(int i = 0; i < primes.size(); i++){
    if(primes[i] % 5 == 1){
      cnt++;
      cout << primes[i] << " ";
    }
    if(cnt == n){
      cout << endl;
      return 0;
    }
  }
}
