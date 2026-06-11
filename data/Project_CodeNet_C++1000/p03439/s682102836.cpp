#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }

int N;
string a0;

string ask(int i) {
    cout << i << endl;
    string res; cin >> res;
    return res;
}

void f(int l, int r) {
    int mid = (l + r) / 2;
    string res = ask(mid);
    if (res == "Vacant") return;
    if ((mid % 2 == 0 && a0 == res) || (mid % 2 == 1 && a0 != res)) {
        f(mid+1, r);
    } else {
        f(l, mid);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    a0 = ask(0);
    if (a0 == "Vacant") return 0;

    f(1, N);

    return 0;
}