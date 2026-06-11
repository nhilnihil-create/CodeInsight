#include <iostream>
#include <vector>

#define log2(x) (31 - __builtin_clz(x))

using namespace std;

int l, n;
vector<struct Info> out;

struct Info
{
    int u, v, w;

    Info() { }

    Info(int _u, int _v, int _w) : u(_u), v(_v), w(_w) { }
};

inline void Add(int u, int v, int w)
{ out.emplace_back(u + 1, v + 1, w); }

void Output()
{
    cout << n << ' ' << out.size() << endl;
    for (auto i : out)
        cout << i.u << ' ' << i.v << ' ' << i.w << endl;
}

int main()
{
    cin >> l;
    n = log2(l) + 1;
    for (int i = 0; i < n - 1; ++i)
        Add(i, i + 1, 0), Add(i, i + 1, 1 << i);
    int t = 1 << log2(l);
    l ^= t;
    while (l)
    {
        int x = log2(l);
        Add(x, n - 1, t);
        t |= 1 << x, l ^= 1 << x;
    }
    Output();
    return 0;
}