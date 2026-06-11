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
    Sieve s(10000);
    set<int> number;

    rep(i,n) number.insert(i+1);
    int sum = (n+1)*n/2;
    int p = s.f[sum];
    int R = sum/p;

    vector<vector<int>> res(p);
    int group = 0;
    int temp = 0;
    while(!number.empty()){
        for(int i = n; i>=1;--i){
            if(number.count(i)==1){
                if(temp+i<=R){
                    temp+=i;
                    number.erase(i);
                    res[group].push_back(i);
                }
            }
        }
        temp = 0;
        group++;
    }
    vector<int> kinds(n+1);
    rep(i,p){
        for(auto y:res[i]){
            kinds[y]=i;
        }
    }

    vector<P> ans;
    for(int i=1; i<=n;++i){
        for(int j=i; j<=n;++j){
            if(kinds[i]!=kinds[j]){
                P q(i,j);
                ans.push_back(q);
            }
        }
    }
    
    cout << ans.size() << endl;
    for(auto a:ans){
        cout << a.first << " " << a.second << endl;
    }
    
}