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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    cin >> A;
    set<int> check;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        vector<int> get;
        vector<int> save;
        for (int j = 0; j < N; j++) {
            if (check.find(A[j]) != check.end()) {
                if (save.size() >= K) {
                    sort(save.begin(), save.end());
                    for (int k = 0; k + K - 1 < save.size(); k++) {
                        get.push_back(save[k]);
                    }
                }
                save = vector<int>();
            } else {
                save.push_back(A[j]);
            }
        }
        if (save.size() >= K) {
            sort(save.begin(), save.end());
            for (int k = 0; k + K - 1 < save.size(); k++) {
                get.push_back(save[k]);
            }
        }

        if (get.size() < Q) break;
        sort(get.begin(), get.end());
        ans = min(ans, get[Q - 1] - get[0]);
        check.insert(get[0]);
    }
    cout << ans << endl;
}
