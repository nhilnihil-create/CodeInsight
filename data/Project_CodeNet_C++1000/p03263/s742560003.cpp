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
    ll H,W;
    cin>>H>>W;
    vvl grid(W,vl(H));
    vector<tuple<ll,ll,ll,ll>> vec;
    rep(i,H){
        rep(j,W){
            cin>>grid.at(j).at(i);
        }
    }
    ll count=0;
    rep(i,H){
        if(i%2==0){
            rep(j,W){
                if(j==W-1&&i==H-1){
                    break;
                }
                if(grid.at(j).at(i)%2==1){
                if(j<W-1){
                    tuple<ll,ll,ll,ll> x;
                    x=make_tuple(i+1,j+1,i+1,j+2);
                    grid.at(j+1).at(i)++;
                    vec.push_back(x);
                    count++;
                }else{
                    tuple<ll,ll,ll,ll> x;
                    x=make_tuple(i+1,j+1,i+2,j+1);
                    grid.at(j).at(i+1)++;
                    vec.push_back(x);
                    count++;
                }
                }
            }
        }else{
            for(ll j=W-1;j>=0;j--){
                if(j==0&&i==H-1){
                    break;
                }
                if(grid.at(j).at(i)%2==1){
                if(j>0){
                    tuple<ll,ll,ll,ll> x;
                    x=make_tuple(i+1,j+1,i+1,j);
                    grid.at(j-1).at(i)++;
                    vec.push_back(x);
                    count++;
                }else{
                    tuple<ll,ll,ll,ll> x;
                    x=make_tuple(i+1,j+1,i+2,j+1);
                    grid.at(j).at(i+1)++;
                    vec.push_back(x);
                    count++;
                }
                }
            }

        }
    }
    cout<<count<<endl;
    rep(i,count){
        cout<<get<0>(vec.at(i))<<' '<<get<1>(vec.at(i))<<' ';
        cout<<get<2>(vec.at(i))<<' '<<get<3>(vec.at(i))<<endl;
    }
}