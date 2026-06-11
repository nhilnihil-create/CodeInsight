#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 2;
long long n, height[mxN], beauty[mxN], dp[mxN];

const int INF = 1e9;
class mxsegtree
{
public:
    int N;
    vector<long long> tree;
    mxsegtree(){}
    void initialize(int s)
    {
        int pos = ceil(log2(s));
        N = 1 << pos;
        tree.resize(2 * N);
        fill(tree.begin(), tree.end(), 0);
    }

    long long qmax(int a, int b)
    {
        a += N;
        b += N;
        long long rmax = 0;
        while (a <= b)
        {
            if (a % 2 == 1)
                rmax = max(tree[a++], rmax);
            if (b % 2 == 0)
                rmax = max(tree[b--], rmax);
            a /= 2;
            b /= 2;
        }
        return rmax;
    }

    void update(long long k, long long newVal)
    {
        k += N;
        tree[k] = max(tree[k], newVal);
        for (k /= 2; k >= 1; k /= 2)
        {
            tree[k] = max(tree[2 * k], tree[2 * k + 1]);
        }
    }
};

mxsegtree seg;

int main()
{
    cin >> n;
    seg.initialize(n + 1);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    for (int i = 0; i < n; i++)
        cin >> beauty[i];
    
    long long ret = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = seg.qmax(1, height[i]) + beauty[i];
        seg.update(height[i], dp[i]);
        ret = max(ret, dp[i]);
    }
    cout << ret << endl;
}