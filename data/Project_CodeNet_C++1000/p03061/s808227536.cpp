#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <functional>

using namespace std;
typedef long long ll;

template <class Monoid>
struct SegTree
{
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid &unity) : F(f), UNITY(unity) { init(n); }
    void init(int n)
    {
        SIZE_R = 1;
        while (SIZE_R < n)
            SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }

    void set(int a, const Monoid &v)
    {
        dat[a + SIZE_R] = v;
    }

    void build()
    {
        for (int k = SIZE_R - 1; k > 0; --k)
        {
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
        }
    }
    void update(int a, const Monoid &v)
    {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1)
        {
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
        }
    }

    Monoid get(int a, int b)
    {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                vleft = F(vleft, dat[left++]);
            if (right & 1)
                vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator[](int a) { return dat[a + SIZE_R]; }
    void print()
    {
        for (int i = 0; i < SIZE_R; i++)
        {
            cout << (*this)[i];
            if (i != SIZE_R - 1)
                cout << ",";
        }
        cout << endl;
    }
};

ll GCD(ll a, ll b)
{
    if (a < b)
    {
        swap(a, b);
    }

    return b ? GCD(b, a % b) : a;
}

int main()
{
    int N;
    cin >> N;

    SegTree<long long> seg(
        N, [](long long a, long long b) {
            return GCD(a, b);
        },
        0);
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        seg.set(i, A[i]);
    }
    seg.build();

    long long res = 0;
    for (int i = 0; i < N; ++i)
    {
        long long left = seg.get(0, i);
        long long right = seg.get(i + 1, N);
        res = max(res, GCD(left, right));
    }
    cout << res << endl;
    return 0;
}