#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - 1e8;
const ll INFLL = numeric_limits<ll>::max() - 1e17;

signed main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<char, char>> move(Q);
    for (int i = 0; i < Q; i++) cin >> move[i].first >> move[i].second;
    auto simulation = [&](int idx, bool goalLeft) {
        for (int i = 0; i < Q; i++) {
            if (S[idx] == move[i].first) {
                if (move[i].second == 'L') idx--;
                else idx++;
            }
            if (idx == -1 || idx == N) break;
        }
        if (goalLeft) {
            return idx == -1;
        } else {
            return idx == N;
        }
    };
    int ansLeft = 0, ansRight = N - 1;
    {
        int left = -1, right = N;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (simulation(mid, true)) left = mid;
            else right = mid;
        }
        ansLeft = left;
    }
    {
        int left = -1, right = N;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (simulation(mid, false)) right = mid;
            else left = mid;
        }
        ansRight = right;
    }
    if (ansLeft == 0 && !simulation(0, true)) ansLeft = -1;
    if (ansRight == N - 1 && !simulation(N - 1, false)) ansRight = N;
    cout << ansRight - ansLeft - 1 << endl;
}
