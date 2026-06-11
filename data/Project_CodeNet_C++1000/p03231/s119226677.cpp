#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

class Prints {
private:
    class __Prints {
    public:
        __Prints(const char* sep, const char* term) : sep(sep), term(term) {}
        template <class... Args>
        void operator()(Args&&... args) const { print(std::forward<Args>(args)...); }

    private:
        const char *sep, *term;
        void print() const { std::cout << term; }
        void print_rest() const { std::cout << term; }
        template <class T, class... Tail>
        void print(T&& head, Tail&&... tail) const { std::cout << head, print_rest(std::forward<Tail>(tail)...); }
        template <class T, class... Tail>
        void print_rest(T&& head, Tail&&... tail) const { std::cout << sep << head, print_rest(std::forward<Tail>(tail)...); }
    };

public:
    Prints() {}
    __Prints operator()(const char* sep = " ", const char* term = "\n") const { return __Prints(sep, term); }
    template <class T>
    void print_vec(const std::vector<T>& vec, const char* sep = " ", const char* term = "\n") const {
        const size_t sz = vec.size();
        for (size_t i = 0; i < sz; i++) std::cout << vec[i] << (i == sz - 1 ? term : sep);
    }
};

Prints prints;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;
    ll l = lcm(N, M);
    bool ok = true;
    ll n1 = l / N, m1 = l / M;
    ll idx1 = 0, idx2 = 0;
    while (idx1 < N && idx2 < M) {
        if (A[idx1] != B[idx2]) {
            ok = false;
            break;
        }
        idx1 += m1;
        idx2 += n1;
    }
    if (ok) {
        prints()(l);
    }
    else {
        prints()(-1);
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    cout << setprecision(18) << fixed;
    solve();
    cout << flush;
    return 0;
}