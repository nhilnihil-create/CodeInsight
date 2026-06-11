#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int MOD = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;

int main()
{
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++) cin >> arr.at(i);

    B = *max_element(all(arr));
    C = *min_element(all(arr));
    cout << B-C;
    return 0;
}