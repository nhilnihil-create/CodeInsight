typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll const MOD = 1e9+7; 

long long modpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
      if (n & 1) res = res * a % MOD;
      a = a * a % MOD;
      n >>= 1;
  }
  return res;
}

int main() {
    string s;
    ll anum[100010];
    ll cnum[100010];
    ll anum2[100010];
    ll cnum2[100010];
    Fill(anum,0);
    Fill(cnum,0);

    Fill(anum2,0);
    Fill(cnum2,0);

    std::cin >> s;
    
    ll n = s.length();
    for (int i = 0; i < n; i++) {
        anum[i+1] = anum[i];
        anum2[i+1] = anum2[i];
        if(s[i] == 'A' ){
            anum[i+1]++;
        }
        if(s[i] == '?' ){
            anum2[i+1]++;
        }
    }
    // 0はなにも含まない
    
    // nは何も含まない
    for (int i = n-1; i >= 0; i--) {
        cnum[i] = cnum[i+1];
        cnum2[i] = cnum2[i+1];
        if(s[i] == 'C'){
            cnum[i]++;
        }
        if(s[i] == '?'){
            cnum2[i]++;
        }
    }
    
    ll result = 0;
    for (int i = 1; i < n-1; i++) {
        ll sum = anum2[i]+cnum2[i+1];
        if(s[i] == 'B' || s[i] == '?'){
            result += anum[i]*cnum[i+1]%MOD*modpow(3,sum)%MOD;
            result += anum2[i]*cnum2[i+1]%MOD*modpow(3,sum-2)%MOD;
            result += anum[i]*cnum2[i+1]%MOD*modpow(3,sum-1)%MOD;
            result += cnum[i+1]*anum2[i]%MOD*modpow(3,sum-1)%MOD;
            result %= MOD;
        }
    }
    
    std::cout << result << std::endl;
    
}
