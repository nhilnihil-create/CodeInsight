#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int maxVal = 0, maxIdx = -1;
    rep(i, N) {
        if(abs(A[i]) >= maxVal) {
            maxVal = abs(A[i]);
            maxIdx = i;
        }
    }
    vector<pii> operation;
    if(A[maxIdx] == 0) {
        
    } else if(A[maxIdx] > 0) {
        rep(i, N) {
            if(A[i] < 0) {
                A[i] += A[maxIdx];
                operation.push_back({maxIdx+1, i+1});
            }
        }
        rep(i, N - 1) {
            A[i+1] += A[i];
            operation.push_back({i+1, i+2});
        }
    } else {
        for(int i = N-1; i >= 0; --i) {
            if(A[i] > 0) {
                A[i] += A[maxIdx];
                operation.push_back({maxIdx+1, i+1});
            }
        }
        for(int i =N-1; i> 0; --i) {
            A[i-1] += A[i];
            operation.push_back({i+1, i});
        }
    }
    cout << sz(operation) << "\n";
    for(auto &p : operation) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
