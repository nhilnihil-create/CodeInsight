#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<int mod>
struct Ring_mod {
    int val;
    Ring_mod(): val(0) {}
    Ring_mod(long long x)
    {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        if (x >= mod) x %= mod;
        val = x;
    }
    explicit operator int() { return val; }
    Ring_mod operator+(const Ring_mod& b) { return Ring_mod(val + b.val); }
    Ring_mod operator-(const Ring_mod& b) { return Ring_mod(val - b.val); }
    void operator+=(const Ring_mod& b) { val = Ring_mod(val + b.val).val; }
    void operator-=(const Ring_mod& b) { val = Ring_mod(val - b.val).val; }
    Ring_mod operator*(const Ring_mod& b) { return Ring_mod((long long) val * b.val); }
};

const int MOD = 1e9 + 7;
typedef Ring_mod<MOD> int_mod;

template<typename T>
struct Matrix {
    Matrix(int r, int c) : _r(r), _c(c), a(r * c) {}
    T* operator[](int row) { return row * _c + a.data(); }
    int _r, _c;
    vector<T> a;
};

int main()
{
    int n;
    string s;
    cin >> n >> s;

    Matrix<int_mod> p(n + 1, n + 1);

    for (int j = 1; j <= n; ++j)
        p[n][j] = j;

    for (int i = n - 1; i >= 1; --i)
        for (int j = 1; j <= i; ++j) {
            if (s[n - 1 - i] == '<')
                p[i][j] = p[i + 1][j];
            else
                p[i][j] = p[i + 1][i + 1] - p[i + 1][j];
            p[i][j] += p[i][j - 1];
        }

    cout << (int) p[1][1];
    return 0;
}
