#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > primes;
  for(int i = 2; i <= 100; i++){
    bool ok = true;
    for(int j = 2; j < i - 1; j++){
      if(i % j == 0) ok = false;
    }
    if(ok) primes.push_back(i);
  }

  vector < ll > cnt(primes.size(), 0);
  for(int i = 2; i <= n; i++){
    int num = i;
    for(int j = 0; j < primes.size() && num > 1; j++){
      while(num % primes[j] == 0){
        num /= primes[j];
        cnt[j]++;
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < primes.size(); i++){
    for(int p = 2; p <= cnt[i] + 1; p++){
      for(int j = i + 1; j < primes.size(); j++){
        for(int q = 2; q <= cnt[j] + 1; q++){
          for(int k = j + 1; k < primes.size(); k++){
            for(int r = 2; r <= cnt[k] + 1; r++){
              if(p * q * r == 75) ans++;
            }
          }
          if(p * q == 75) ans++;
        }
      }
      if(p == 75) ans++;
    }
  }

  cout << ans << '\n';
}
