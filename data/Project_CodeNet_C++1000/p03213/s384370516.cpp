#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct Sieve{
  int n;
  vector<int> f,primes;
  Sieve(int n=1):n(n),f(n+1){
    f[0] = f[1] = -1;
    for(ll i = 2; i<=n;++i){
      if(f[i]) continue; //素数でない場合continue
      primes.push_back(i);
      f[i] = i;
      for(ll j=i*i;j<=n;j+=i){
        if(!f[j]) f[j]=i;
      }
    }
  }
  bool isPrime(int x){
    return f[x]==x;
  }
  vector<int> factorList(int x){
    vector<int> res;
    while(x != 1){
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x){
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1,P(fl[0],0));
    for (int p:fl){
      if(res.back().first == p){
        res.back().second++;
      }else{
        res.emplace_back(p,1);
      }
    }
    return res;
  }
};


int main(){
    int n;
    cin >> n;
    vector<int> freq(101,0);
    Sieve s(101);
    for(int i=2; i<=n; ++i){
        vector<P> f;
        f = s.factor(i);
        for(auto fa:f){
            freq[fa.first]+=fa.second;
        }
    }

    int num2=0; int num4=0; int num14=0; int num24=0; int num74=0;
    rep(i,101){
        //cout << i << ":" << freq[i] << endl;
        if(freq[i]>=2) num2++;
        if(freq[i]>=4) num4++;
        if(freq[i]>=14) num14++;
        if(freq[i]>=24) num24++;
        if(freq[i]>=74) num74++;
    }

    /*
    cout << num2 << endl;
    cout << num4 << endl;
    cout << num14 << endl;
    cout << num24 << endl;
    cout << num74 << endl;
    */
   
    int res=0;
    res+=num74;
    res+=num24*(num2-1);
    res+=num14*(num4-1);
    res+=num4*(num4-1)*(num2-2)/2;

    cout << res << endl;
}