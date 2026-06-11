#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

// WaveletMatrix<T> Tはデータ型
// N要素の配列Aに対する次のクエリを高速に処理する。メモリ使用量はO(N log max x) (max xはデータ型の最大値)
// 1. rank(k, x): Aの先頭から位置kまでに文字xがいくつあるか
// 2. select(n, x): n個目(1-origin)の文字xの次の位置はどこか
// 3. QuantileRange(l, r, n): 位置lと位置rの間で、n番目(1-origin)に小さい数は何か
// 4. RankLessThan(l, r, x): 位置lと位置rの間に、xと同じ数字が何個あるか, xより小さい数字が何個あるか, xより大きい数字が何個あるかを返す
// selectのみ時間がかかる(O(log N log max x))が、その他はO(log max x)で処理可能
// メモリ使用量: T = long long, N = 2*10^5 で 20MBくらい
// また、負の数は制御できない！Aの中やxに負の数が紛れ込まないようにしよう
// usage:
// vector<int> A(N); 
// WaveletMatrix<int> wm(A);

template<typename T>
struct WaveletMatrix {
    // FID
    // 手抜き実装のため、完備辞書にはなっていない (O(N)の追加領域が必要)
    struct FID {
        vector<uint32_t> bit;
        vector<int> acc;
        int N;
        FID(vector<int> &bit_) {
            N = bit_.size();
            int N2 = (N >> 5) + 1;
            bit.resize(N2);
            for(int i = 0; i < N2; i++) {
                for(int j = 0; j < 32; j++) {
                    if ((i << 5) + j < N) bit[i] |= bit_[(i << 5) + j] << j;
                }
            }
            acc = vector<int>(N2);
            for(int i = 0; i < N2 - 1; i++) {
                acc[i + 1] = acc[i] + __builtin_popcount(bit[i]); 
            }
        }
        FID() {}
        // rank: 位置kまでに何個のxがあるかを返す
        // O(1)
        inline int rank(int k, int x = 1) {
            int n1 = acc[k >> 5] + __builtin_popcount(bit[k >> 5] & (uint32_t)(((1ULL << (k & 0x1f)) - 1)));
            return x ? n1 : k - n1;
        }

        // select: ビット列の先頭から見てn個目のxのビットの次の位置はどこか
        // O(log N)
        inline int select(int n, int x = 1) {
            int ng = 0, ok = N + 1;
            while(ok - ng > 1) {
                int c = (ok + ng) / 2;
                if (rank(c, x) >= n) {
                    ok = c;
                } else {
                    ng = c;
                }
            }
            return ok;
        }

        inline int operator[](int k) {
            return ((bit[k >> 5] >> (k & 0x1f)) & 1);
        }

        inline size_t size() {
            return N;
        }
    };

    vector<int> cntZero;
    vector<FID> bits;
    unordered_map<ll, int> pos;
    int level;
    ll mask;

    // rank
    // Aの先頭から位置kまでに文字xがいくつあるか
    // O(log max x)
    inline int rank(int k, T x) {
        int now = k;
        for(int j = level - 1; j >= 0; j--) {
            if (x >> j & 1) {
                now = cntZero[j] + bits[j].rank(now);
            } else {
                now = now - bits[j].rank(now);
            }
        }
        return now - pos[x ^ mask];
    }

    // select: 
    // n個目(1-origin)の文字xの次の位置はどこか
    // O(log N log max x)
    inline int select(int n, T x) {
        int now = pos[x ^ mask] + n;
        for(int j = 0; j < level; j++) {
            if (x >> j & 1) {
                int w = now - cntZero[j];
                now = bits[j].select(w);
            } else {
                now = bits[j].select(now, 0);
            }
        }
        return now;
    }

    // QuantileRange
    // 位置lと位置rの間で、n番目(1-origin)に小さい数は何か
    // 「数」と「その数と同じ数の中で、先頭から数えて何番目か」を返す
    // O(log max x)
    inline pair<T, int> QuantileRange(int l, int r, int n) {
        T ans = 0;
        for(int j = level - 1; j >= 0; j--) {
            ans <<= 1LL;
            int nz = bits[j].rank(r, 0) - bits[j].rank(l, 0);
            if (n > nz) {
                n -= nz;
                l = bits[j].rank(l, 1) + cntZero[j];
                r = bits[j].rank(r, 1) + cntZero[j];
                ans |= 1LL;
            } else {
                l = bits[j].rank(l, 0);
                r = bits[j].rank(r, 0);
            }
        }
        return {ans, l + n - pos[ans ^ mask]};
    }

    // RankLessThan
    // 位置lと位置rの間に、xと同じ数字が何個あるか, xより小さい数字が何個あるか, xより大きい数字が何個あるかを返す
    // tuple<int, int, int> ret = wm.RankLessThan(0, N, x); int eq = get<0>(ret), less = get<1>(ret), greater = get<2>(ret);
    // O(log max x)
    inline tuple<int, int, int> RankLessThan(int l, int r, T x) {
        T n_eq = 0, n_less = 0, n_greater = 0;
        for(int j = level - 1; j >= 0; j--) {
            if (x >> j & 1) {
                n_less += bits[j].rank(r, 0) - bits[j].rank(l, 0);
                l = bits[j].rank(l, 1) + cntZero[j];
                r = bits[j].rank(r, 1) + cntZero[j];
            } else {
                n_greater += bits[j].rank(r, 1) - bits[j].rank(l, 1);
                l = bits[j].rank(l, 0);
                r = bits[j].rank(r, 0);
            }
        }
        n_eq = r - l;
        return make_tuple(n_eq, n_less, n_greater);
    }

    WaveletMatrix(vector<T> A_) : level(sizeof(T) * 8) {
        cntZero.resize(level);
        bits.resize(level);
        vector<T> zero(A_.size());
        vector<T> one(A_.size());
        for(int j = level - 1; j >= 0; j--) {
            int n0 = 0, n1 = 0;
            vector<int> bit(A_.size());
            int cnt = 0;
            for(int i = 0; i < A_.size(); i++) {
                if (A_[i] >> j & 1) {
                    one[n1++] = A_[i];
                    bit[i] = 1;
                } else {
                    zero[n0++] = A_[i];
                    cnt++;
                }
            }
            vector<T> newA(zero.begin(), zero.begin() + n0);
            newA.insert(newA.end(), one.begin(), one.begin() + n1);
            A_ = std::move(newA);
            bits[j] = FID(bit);
            cntZero[j] = cnt;
        }
        //reverse(bits.begin(), bits.end());
        mask = random_device()();
        for(int i = 0; i < A_.size(); i++) {
            if (pos.find(A_[i]) == pos.end()) {
                pos[A_[i] ^ mask] = i;
            }
        }
    }

    void show() {
        cout << "cntZero: ";
        for (int i = 0; i < cntZero.size(); i++) {
            cout << cntZero[i] << ", ";
        }
        cout << endl;
        cout << "bits: " << endl;
        for (int j = 0; j < level; j++) {
            for (int i = 0; i < bits[j].size(); i++) {
                cout << bits[j][i] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

ll get(int c, vector<int> &A) {
    int N = A.size();
    vector<int> acc(N + 1);
    for (int i = 0; i < N; i++) {
        acc[i + 1] = acc[i] + (A[i] <= c ? 1 : -1);
    }
    for (int i = 0; i <= N; i++) {
        acc[i] += 2000000;
    }

    WaveletMatrix<int> wm(acc);
    ll ans = 0;
    for (int i = 1; i <= N + 1; i++) {
        ans += get<1>(wm.RankLessThan(0, i, acc[i - 1]));
    }
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll M = N * (N + 1) / 2;

    int ok = 0, ng = 1e9 + 1;
    while(ng - ok > 1) {
        ll c = (ok + ng) / 2;
        if (get(c, A) >= M / 2 + 1) {
            ng = c;
        } else {
            ok = c;
        }
    }
    cout << ng << endl;

}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
