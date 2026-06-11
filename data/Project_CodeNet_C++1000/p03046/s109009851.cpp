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

// ■ XORの性質1
// 　 0,1,2,3 のXORは0、0,1,...,7のXORは0
// 　 0〜2の冪乗-1までのXORは0になる
// ■ XORの性質2
// 　 区間内に同じ数字が偶数回出現する場合はその要素は打ち消し合うと考えて良い
// ■ XORの性質3
// 　 XORは桁上げの生じない加算であるため、(この問題の制約下では)2の冪乗-1以上の数値にはならない

int main(){
    Init();
    ll m, k; cin >> m >> k;
    ll lim = pow(2, m);

    // kが2^(m+1)_-1より大きい場合（達成不可能な場合）
    if(lim <= k) cout << -1 << endl; 

    // m=0の場合
    else if(m == 0) cout << (k == 0 ? "0 0" : "-1") << endl;
    
    // m=1の場合
    else if(m == 1) cout << (k == 0 ? "0 0 1 1" : "-1") << endl;

    // m>=2の場合
    else{
        // 0〜2の冪乗-1までの数字をkを除いて昇順に並べたものAsce
        // Asceを逆順に並べ替えたものAdes
        // Asce k Ades kが答えとなる
        for(ll i=0; i<lim; i++) if(i != k) cout << i << " ";
        cout << k << " ";
        for(ll i=lim-1; i>=0; i--) if(i != k) cout << i << " ";
        cout << k << endl;
    }
}