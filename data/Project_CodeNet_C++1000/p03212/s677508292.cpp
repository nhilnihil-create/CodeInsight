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
ll N;
ll Ans=0;

void dfs(ll num,ll &res,ll use7,ll use5,ll use3){
    if(num>N){
        return;
    }
    if(use7>0&&use5>0&&use3>0){
        res++;
    }
    dfs(num*10+7,res,use7+1,use5,use3);
    dfs(num*10+5,res,use7,use5+1,use3);
    dfs(num*10+3,res,use7,use5,use3+1);
}

int main() {
    cin>>N;
    dfs(0,Ans,0,0,0);
    cout<<Ans<<endl;
}