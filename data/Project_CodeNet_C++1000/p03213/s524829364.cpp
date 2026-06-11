#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000000000000001;
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N/=a;
        }
        //その結果をpush
        res.push_back({a,ex});
    }
    //残った数について
    if(N!=1)res.push_back({N,1});
    return res;
}
int main(){
    ll n;cin>>n;
    vector<ll> ex(n+1,0);
    ll cnt=0;
    for(ll i=0;i<=n;i++){
        vector<pair<ll,ll>> res=prime_factorize(i);
        for(auto p:res){
            ex[p.first]+=p.second;
        }
    }
    ll b[5]={0};
    for(ll i=2;i<=n;i++){
      if(ex[i]>=74)b[4]++;
      if(ex[i]>=24)b[3]++;
      if(ex[i]>=14)b[2]++;
      if(ex[i]>=4)b[1]++;
      if(ex[i]>=2)b[0]++;
    }
    ll ans=0;
        ans=b[4]+(b[0]-1)*b[3]+(b[1]-1)*b[2]+(b[0]-2)*(b[1]-1)*(b[1])/2;
        cout << ans << endl;
        return 0;
}