#include <bits/stdc++.h>
using namespace std;

// 3. bit（bitset高速化をする）

const int MAX_ROW = 510; // to be set appropriately
const int MAX_COL = 510; // to be set appropriately
struct BitMatrix {
    int H, W; // H * W 行列
    bitset<MAX_COL> val[MAX_ROW]; // MAX_ROW *　MAX_COL 行列
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};
// rankを求める
int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < (int)A.W; col++) {
        if (is_extended && col == (int)A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < (int)A.H; row++) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        if (rank != pivot) swap(A[pivot], A[rank]);
        for (int row = 0; row < (int)A.H; row++) {
            if (row != rank && A[row][col] != 0)  A[row] ^= A[rank];
        }
        rank++;
    }
    return rank;
}
// 連立一次方程式を解く（解が一つだけ存在するor存在しない）（resに参照渡しする）
int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = (int)A.H, n = (int)A.W;
    BitMatrix M(m, n+1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row) if (M[row][n] != 0) return -1;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}

int main(){
    int n, m; cin >> n >> m;
    BitMatrix A(m, n);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int s; cin >> s; s--;
            A[i][s] = 1;
        }
    }
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> res;
    int rank = linear_equation(A, b, res);
    if (rank == -1) cout << 0 << endl;
    else cout << (1<<(n-rank)) << endl;
}