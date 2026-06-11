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

using Data = pair<ll, vector<int>>;

int main() {

    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll> A(X), B(Y), C(Z);
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];

    sort(A.begin(),A.end(), greater<ll>());
    sort(B.begin(),B.end(), greater<ll>());
    sort(C.begin(),C.end(), greater<ll>());

    priority_queue<Data> que;
    set<Data> se; // 同じ組み合わせが使われないように使ったものは集合として保存していく

    Data insert;
    insert = make_pair(A[0] + B[0] + C[0], vector<int>({0, 0, 0}));
    que.push(insert);


    rep(i,K){
        // 出力
        auto c = que.top();que.pop();
        cout << c.first << endl;

        // 次の三候補をpush

//        A のみ index を 1 個進めて足したもの
        if (c.second[0] + 1 < X) {
            ll sum = c.first - A[c.second[0]] + A[c.second[0] + 1];
            auto num = c.second;
            num[0]++;
            auto d = Data(sum, num);

            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }

//        B のみ index を 1 個進めて足したもの
        if (c.second[1] + 1 < Y) {
            ll sum = c.first - B[c.second[1]] + B[c.second[1] + 1];
            auto num = c.second;
            num[1]++;
            auto d = Data(sum, num);

            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }

//        C のみ index を 1 個進めて足したもの
        if (c.second[2] + 1 < Z) {
            ll sum = c.first - C[c.second[2]] + C[c.second[2] + 1];
            auto num = c.second;
            num[2]++;
            auto d = Data(sum, num);

            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }
    }

}