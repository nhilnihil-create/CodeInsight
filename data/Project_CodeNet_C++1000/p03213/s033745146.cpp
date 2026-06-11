#include<bits/stdc++.h>
#define rep(i, n) for (ll i=0;i<(n);i++)
using namespace std;
#define vecout(v) for(int i=0;i<v.size();i++) {cout<<v[i]<<endl;}
typedef long long ll;

map<int, int> mp;

map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int num(int m){
    int res=0;
    for(auto p : mp){
        if(p.second>=m) res++;
    }
    return res;
}

int main(void){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(auto p : prime_factor(i)){
            mp[p.first]+=p.second;
        }
    }
    int ans=(num(74)+num(24)*(num(2)-1)+num(14)*(num(4)-1)+num(4)*(num(4)-1)*(num(2)-2)/2);
    cout<<ans<<endl;
    return 0;
}