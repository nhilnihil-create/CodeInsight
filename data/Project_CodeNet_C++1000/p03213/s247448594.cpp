#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
long long N;
    cin >> N;
    //pairの書き換えが煩雑であるので、素数リストと指数連想配列に分ける
   map<ll,ll> prime_count;
   vector<ll> prime_list;
   rep3(j,N){
    //resに素数のペア(素数、その素数の指数）の配列が入る
    const auto  &res = prime_factorize(j);
    
   rep(i,res.size()){
       if(prime_count[res[i].first]==0){
           prime_list.push_back(res[i].first);
       }
       prime_count[res[i].first]+=res[i].second;
   }
   }
   int num_2=0,num_4=0,num_14=0,num_24=0,num_74=0;
   rep(i,prime_list.size()){
       int p=prime_list[i];
       if(prime_count[p]>=2){
           num_2++;
       }
       if(prime_count[p]>=4){
           num_4++;
       }
       if(prime_count[p]>=14){
           num_14++;
       }
       if(prime_count[p]>=24){
           num_24++;
       }
       if(prime_count[p]>=74){
           num_74++;
       }
   }
   ll ans;
   ans=num_74+num_14*(num_4-1)+num_24*(num_2-1)+(num_4*(num_4-1)*(num_2-2))/2;
   cout<<ans<<endl;
   
    
return 0;
}
