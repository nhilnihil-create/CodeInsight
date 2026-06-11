#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,h;
    cin >> n >> h;
    vi a(n), b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    // 基本的には一番強いもの: 最大のaを使う
    // aより大きいbは使っても良さそう
    // 最大のやつが無制限に使えて、他が1回しか使えない
    // ナップザックと同じか?
    // どのbを使うか、使わないかで、2^n通りのパターンがありそう
    // i番目までを使うときと、i+1番目を使うときとで関係がある
    // どれも使わない最強, 1を使う最小, 2を使う最小...をやっていけばよさそう
    vi a_ = a;
    sort(a_.begin(), a_.end(), greater<>());
    int64_t maxa = a_.at(0);
    // あれaの最大よりでかいやつはずっと使えば良いのでは…？
    vi stronger;
    rep(i,n){
        if(b.at(i) > maxa){
            stronger.push_back(b.at(i));
        }
    }
    sort(stronger.begin(), stronger.end(), greater<>());
    int64_t res = 0;
    rep(i,stronger.size()){
        h -= stronger.at(i);
        res++;
        if(h<=0){
            break;
        }
    }
    if(h>0){
        res += (h/maxa);
        if(h%maxa!=0) res++;
    }
    cout << res << endl;
}