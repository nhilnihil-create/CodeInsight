#include <bits/stdc++.h>
using namespace std;

// 2. mod.p (数値誤差なし)

using ll = long long;
// 逆元計算
ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a/b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return (u % mod + mod) % mod;
}
// matrix
template<int MOD> struct Matrix {
    vector<vector<long long> > val;
    Matrix(int n, int m, long long x = 0) : val(n, vector<long long>(m, x)) {}
    void init(int n, int m, long long x = 0) {val.assign(n, vector<long long>(m, x));}
    int size() const { return (int)val.size(); }
    inline vector<long long>& operator [] (int i) { return val[i]; }
};
// rankを求める
template<int MOD> int GaussJordan(Matrix<MOD> &A, bool is_extended = false) {
    int m = (int)A.size(), n = (int)A[0].size();
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            A[row][col] = (A[row][col] % MOD + MOD) % MOD;
        }
    }
    
    int rank = 0;
    for (int col = 0; col < n; col++) {
        if (is_extended && col == n-1) break;
        int pivot = -1;
        for (int row = rank; row < m; row++) {
            if (A[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        if (rank != pivot) swap(A[pivot], A[rank]);
        auto inv = modinv(A[rank][col], MOD); // 逆元
        for (int col2 = 0; col2 < n; ++col2) {
            A[rank][col2] = A[rank][col2] * inv % MOD;
        }
        for (int row = 0; row < m; row++) {
            if (row != rank && A[row][col] != 0) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; col2++) {
                    A[row][col2] -= A[rank][col2] * fac % MOD;
                    if (A[row][col2] < 0) A[row][col2] += MOD;
                }
            }
        }
        rank++;
    }
    return rank;
}
// 連立一次方程式を解く（解が一つだけ存在するor存在しない）（resに参照渡しする）
template<int MOD> int linear_equation(Matrix<MOD> A, vector<ll> b, vector<ll> &res) {
    int m = (int)A.size(), n = (int)A[0].size();
    Matrix<MOD> M(m, n+1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; row++) if (M[row][n] != 0) return -1;

    // answer (only 1)
    res.assign(n, 0);
    for (int i = 0; i < rank; i++) res[i] = M[i][n];
    return rank;
}

int main(){
    int n, m; cin >> n >> m;
    Matrix<2> A(m, n, 0);
    vector<ll> b(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int s; cin >> s; s--;
            A[i][s] = 1;
        }
    }
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<ll> res;
    int rank = linear_equation<2>(A, b, res);
    if (rank == -1) cout << 0 << endl;
    else cout << (1<<(n-rank)) << endl;
}