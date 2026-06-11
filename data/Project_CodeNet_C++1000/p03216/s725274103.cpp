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
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main() {
    int N;
    string S;
    cin >> N >> S;
    int Q;
    cin >> Q;
    vector<int> k(Q);
    cin >> k;
    for (int range : k) {
        int ans = 0;
        int D = 0, M = 0, sum = 0;
        for (int i = 0; i < range; i++) {
            if (S[i] == 'D') D++;
            if (S[i] == 'M') {
                M++;
                sum += D;
            }
            if (S[i] == 'C') ans += sum;
        }
        for (int i = 0; i + range < N; i++) {
            if (S[i] == 'D') {
                sum -= M;
                D--;
            }
            if (S[i] == 'M') M--;
            if (S[i + range] == 'D') D++;
            if (S[i + range] == 'M') {
                M++;
                sum += D;
            }
            if (S[i + range] == 'C') ans += sum;
        }
        cout << ans << endl;
    }
}
