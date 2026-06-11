#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
const long double pi = (acos(-1));
#define pb push_back

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//切り上げの割り算は(a + b - 1) / bでできる
//時間を意識しろ
//コードテストちゃんとして
//画面とにらめっこするな書け
//WA出すたびにABCは五億円払え
//わからない問題はとばせ
//躊躇なくぐぐれ

//ここから
int main(){
    ll n;
    cin>>n;
    map<ll,ll> e;
    map<ll,ll> o;
    rep(i,n){
        ll a;
        cin>>a;
        if(i%2==0){
            e[a]++;
        }else{
            o[a]++;
        }
    }
    ll keye,keyo;
    ll emax=0;
    ll e2m=0;
    ll omax=0;
    ll o2m=0;
    for(auto p:e){
        ll value=p.second;
        if(value>emax){
            e2m=emax;
            emax=value;
            keye=p.first;
        }else if(value>e2m){
            e2m=value;
        }
    }
    for(auto p:o){
        ll value=p.second;
        if(value>omax){
            o2m=omax;
            omax=value;
            keyo=p.first;
        }else if(value>o2m){
            o2m=value;
        }
    }
    if(keye!=keyo){
        cout<<n-emax-omax<<endl;
    }else{
        if(omax+e2m>emax+o2m){
            cout<<n-omax-e2m<<endl;
        }else{
            cout<<n-emax-o2m<<endl;
        }
    }
}