// https://atcoder.jp/contests/abc123/tasks/abc123_d
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

#define isvisiblechar(c) (0x21 <= (c) && (c) <= 0x7E)
#define cin scanner
#define cout printer
#define endl '\n'
namespace {
class MaiScanner {
  public:
    template <typename T> void input_integer(T &var) {
        var = 0;
        char ch = getchar_unlocked(), sign = 1;
        while (ch < '0' || ch > '9') {
            if (ch == '-')
                sign = -1;
            ch = getchar_unlocked();
        }
        while (ch >= '0' && ch <= '9')
            var = (var << 3) + (var << 1) + ch - '0', ch = getchar_unlocked();
        var = var * sign;
    }
    inline MaiScanner &operator>>(int &var) {
        input_integer<int>(var);
        return *this;
    }
    inline MaiScanner &operator>>(long long &var) {
        input_integer<long long>(var);
        return *this;
    }
    inline MaiScanner &operator>>(string &var) {
        char cc = getchar_unlocked();
        for (; !isvisiblechar(cc); cc = getchar_unlocked())
            ;
        for (; isvisiblechar(cc); cc = getchar_unlocked())
            var.push_back(cc);
        return *this;
    }
    template <typename IT> void in(IT begin, IT end) {
        for (auto it = begin; it != end; ++it)
            *this >> *it;
    }
};
class MaiPrinter {
  public:
    template <typename T> void output_integer(T var) {
        if (var == 0) {
            putchar_unlocked('0');
            return;
        }
        if (var < 0)
            putchar_unlocked('-'), var = -var;
        char stack[32];
        int stack_p = 0;
        while (var)
            stack[stack_p++] = '0' + (var % 10), var /= 10;
        while (stack_p)
            putchar_unlocked(stack[--stack_p]);
    }
    inline MaiPrinter &operator<<(char c) {
        putchar_unlocked(c);
        return *this;
    }
    inline MaiPrinter &operator<<(int var) {
        output_integer<int>(var);
        return *this;
    }
    inline MaiPrinter &operator<<(long long var) {
        output_integer<long long>(var);
        return *this;
    }
    inline MaiPrinter &operator<<(char *str_p) {
        while (*str_p)
            putchar_unlocked(*(str_p++));
        return *this;
    }
    inline MaiPrinter &operator<<(const string &str) {
        const char *p = str.c_str();
        const char *l = p + str.size();
        while (p < l)
            putchar_unlocked(*p++);
        return *this;
    }
    template <typename IT> void join(IT begin, IT end, char sep = ' ') {
        for (bool b = 0; begin != end; ++begin, b = 1)
            b ? *this << sep << *begin : *this << *begin;
    }
};
} // namespace
MaiScanner scanner;
MaiPrinter printer;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<long long> A(X), B(Y), C(Z);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    for (auto &x : C)
        cin >> x;
    sort(ALLR(A));
    sort(ALLR(B));
    sort(ALLR(C));
    vector<long long> ans;
    REP(a, X) {
        REP(b, Y) {
            if ((a + 1) * (b + 1) > K) {
                break;
            }
            REP(c, Z) {
                if ((a + 1) * (b + 1) * (c + 1) > K) {
                    break;
                }
                ans.emplace_back(A[a] + B[b] + C[c]);
            }
        }
    }
    sort(ALLR(ans));
    REP(i, K) { cout << ans[i] << "\n"; }

    return 0;
}
