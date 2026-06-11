#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 505;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int> > a(MAX, vector<int>(MAX));
    int l, r;
    for (int i = 0; i < M; i++) {
        cin >> l >> r;
        a[l][r]++;
    }
    // [l, r)内に含まれる個数の累積和
    vector<vector<int> > sum(MAX + 1, vector<int>(MAX + 1));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        // [l, r)より r = r+1に変更している
        cout << sum[r+1][r+1] - sum[r+1][l] - sum[l][r+1] + sum[l][l] << '\n';
    }

}