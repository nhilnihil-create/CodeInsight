#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


set<int> E[202020]; //自己ループの可能性があるのとbfsで辺を消していきたいのでset
int A[202020], B[202020];

int main() {
    
    int N, M; cin >> N >> M;
    string S; cin >> S;

    rep(i, M) {
        int x,y; cin >> x >> y;
        E[x - 1].insert(y - 1);
        E[y - 1].insert(x - 1);
    }
    

    set<int> Q;
    rep(i, N) {
        for (auto e : E[i]) {
            if (S[e] == 'A') A[i]++;
            if (S[e] == 'B') B[i]++;
        }
        if (A[i] == 0 || B[i] == 0) Q.insert(i);
    }


    int lef = N;
    while (Q.size()) {
        int x = *Q.begin();
        Q.erase(Q.begin());
        lef--;
        for(auto e : E[x]) if (e != x) {
            E[e].erase(x);
            if (S[x] == 'A') A[e]--;
            if (S[x] == 'B') B[e]--;
            if (A[e] == 0 || B[e] == 0) Q.insert(e);
        }
    }

    if (lef) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}