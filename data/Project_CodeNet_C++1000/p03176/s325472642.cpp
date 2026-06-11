#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;



#include <bits/stdc++.h>
using namespace std;

//このSegmentTreeは最小値を扱う仕様になっている
struct SegmentTree {
private:
    ll n;
    vector<ll> node;
    ll INF = 1e18;
public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
    void update(ll x, ll val) {
        // x番目をvalに変える
        // 最下段のノードにアクセスする
        x += (n - 1);

        // 最下段のノードを更新したら、あとは親に上って更新していく
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    ll get_X(ll x){
        return node[x];
    }
    
    // 要求区間 [a, b) 中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる

    ll get_min(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        // 最初に呼び出されたときの対象区間は [0, n)
        if(r < 0) r = n;

        // 要求区間と対象区間が交わらない -> 適当に返す
        if(r <= a || b <= l) return INF;

        // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
        if(a <= l && r <= b) return node[k];

        // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
        // 左側の子を vl ・ 右側の子を vr としている
        // 新しい対象区間は、現在の対象区間を半分に割ったもの
        ll vl = get_min(a, b, 2*k+1, l, (l+r)/2);
        ll vr = get_min(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};



// DP : Nこめまで読んだ時のMax
// tail : DPの時の部分列の最大値
// Max : 部分列の末尾がNの時のAの合計のMax




int main() {
    ll N; cin >> N;
    vector<ll> A(N), H(N), DP(N+1), tail(N+1), Max(N+2);
    
    for(int i = 0; i < N; i++) cin >> H[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    DP[1] = A[0];
    tail[1] = H[0];
    Max[H[0]] = -A[0];
    SegmentTree tree(Max);

    for(int i = 2; i <= N; i++) {
        if(tail[i-1] < H[i-1]) { // 即決で使う
            DP[i] = DP[i-1] + A[i-1];
            tail[i] = H[i-1];
            tree.update(tail[i], -DP[i]);
        }
        else { // 使うか使わないかわからない
        // 今までのDPの値と、A[N]を使った場合の値を比べて決めたい

            ll comp1 = DP[i-1]; // 使わなかった場合
            ll temp = tree.get_min(0, H[i-1])*(-1);
            ll comp2 = A[i-1] + temp; // 使った場合

            if(comp1 < comp2){ //使った場合
                DP[i] = comp2;
                tail[i] = H[i-1];
                Max[tail[i]] = DP[i];
                tree.update(tail[i], -DP[i]);
            }
            else{
                DP[i] = DP[i-1];
                tail[i] = tail[i-1];
                Max[H[i-1]] = Max[H[i-1]-1]+A[i-1];
                //tree.update(Max[H[i-1]], -temp-A[i-1]);
                //cout << H[i-1] << endl;
                //cout << tree.get_X(H[i-1]) << endl;
                tree.update(H[i-1], -temp-A[i-1]);

            }
        }
    }
    cout << DP[N] << endl;
    

}
