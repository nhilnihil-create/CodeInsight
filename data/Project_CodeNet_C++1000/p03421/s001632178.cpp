#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> ans(B);
    if (N < A + B - 1 || N > A * B) {
        cout << -1 << endl;
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= B; i++) ans[i - 1].push_back(i);
    for (int i = B + 1; i <= N; i++) {
        if (ans[count].size() == A) count++;
        ans[count].push_back(i);
    }

    for (int i = B - 1; i >= 0; i--) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << (i == 0 && j == ans[i].size() - 1 ? '\n' : ' ');
        }
    }
}
