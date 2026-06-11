#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> bool chmin(T &a, T b){
    if(a>b) {
        a = b;
        return true;
    }
    return false;

}
template<class T> void chmax(T &a, T b){ if(a<b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

// 最大公約数を求める GCD
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }


/*
 *A,B,C はそれぞれ大きい順にソートしておく。まず一番大きいのは A,B,C
 * それぞれの最大値をとったもの A1+B1+C1 で決まりである。ここから priority_queue をうまく用いる。
 * この次に大きいものは

    A2+B1+C1
    A1+B2+C1
    A1+B1+C2
    の 3 つの候補があるが、それぞれをキューに push しておく。このときにキューの先頭にあるものが、2 番目に大きい値になる。

    同様にその 2 番目に大きい値を pop して来て、それに対し

    A のみ index を 1 個進めて足したもの
    B のみ index を 1 個進めて足したもの
    C のみ index を 1 個進めて足したもの
    の 3 通りの値をキューに push していく。そしてこの時点でキューの先頭にあるものが 3 番目の値になる。
    以後これを繰り返して行く。注意点として、「一度 push したものは二度 push しない」という管理が必要となる。

    計算量は、

    キューから pop する回数が K 回
    その K 回それぞれについて、キューの push するのは 3 回以下なので、キューに push する回数も多くても 3K 以下
    ということで、計算量は O(KlogK) となる。
 * */

using Data = pair<ll, vector<int>>;

int main() {
    vector<long long> N(3);
    int K;
    for (int i = 0; i < 3; ++i) cin >> N[i]; cin >> K;
    vector<vector<long long> > v(3);
    for (int iter = 0; iter < 3; ++iter) {
        v[iter].resize(N[iter]);
        for (int i = 0; i < N[iter]; ++i) cin >> v[iter][i];
        sort(v[iter].begin(), v[iter].end(), greater<long long>());
    }
    priority_queue<Data> que;
    set<Data> se;
    que.push(Data(v[0][0] + v[1][0] + v[2][0], vector<int>({0, 0, 0})));
    for (int k = 0; k < K; ++k) {
        auto c = que.top();que.pop();
        cout << c.first << endl;
        
        // 次の三候補
        for (int iter = 0; iter < 3; ++iter) {
            if (c.second[iter] + 1 < N[iter]) {
                long long sum = c.first - v[iter][c.second[iter]] + v[iter][c.second[iter] + 1];
                auto num = c.second; num[iter]++;
                auto d = Data(sum, num);
                
                // すでに push されたもの以外
                if (!se.count(d)) se.insert(d), que.push(d);
            }
        }
    }
}