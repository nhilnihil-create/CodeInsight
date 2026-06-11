#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<long long> ret;

void divisor(long long n) {
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return;
}

int main(){
  ll ans=0;
  ll n; cin>>n;
  divisor(n);
  for(auto x : ret){
    if(x>=(n/x-1)){
      continue;
    }else{
      ans+=n/x-1;
    }
  }
  cout<<ans<<endl;
}