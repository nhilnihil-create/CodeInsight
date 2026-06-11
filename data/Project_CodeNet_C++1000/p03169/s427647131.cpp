#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// メモ化再帰用DPテーブル
vector<vector<vector<double>>> dp(301, vector<vector<double>>(302, vector<double>(302, -1.0)));

// 寿司が1個置かれた皿がi枚、2個置かれた皿がj枚、3個置かれた皿がk枚
double evalue(const long long n, long long i, long long j, long long k){
    // すでに計算済みならその結果を返す
    if(dp[i][j][k] > -1.0) return dp[i][j][k];
    // 全て0なら期待値は0.0を返す
    if(i == 0 && j == 0 && k == 0) return 0.0;
    
    double eval = 1.0*n;
    if(i > 0) eval += i*evalue(n, i-1, j, k);
    if(j > 0) eval += j*evalue(n, i+1, j-1, k);
    if(k > 0) eval += k*evalue(n, i, j+1, k-1);
    return dp[i][j][k] = (eval*(1.0/(i+j+k)));
}

int main(){
    Init();
    ll n; cin >> n;
    vector<long long> cnt(4);
    for(long long i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    cout << evalue(n, cnt[1], cnt[2], cnt[3]) << endl;
}