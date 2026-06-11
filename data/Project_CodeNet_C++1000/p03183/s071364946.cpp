#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 2, mxS = 2e4 + 2;

class Block
{
public:
    Block() {}
    Block(int _weight, int _solid, int _value) {weight = _weight; solid = _solid; value = _value;}

    int weight, solid, value;
};

int n;
long long dp[mxN][mxS];
Block blocks[mxN];

bool cmp(Block& a, Block& b)
{
    return (a.solid + a.weight) < (b.solid + b.weight);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        blocks[i] = Block(a, b, c);
    }

    sort(blocks, blocks + n, cmp);

    long long ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int w = 0; w < mxS; w++)
        {
            // calc dp[i][w]. 
            if (i > 0)
            {
                dp[i][w] = dp[i - 1][w];
                if (min(w - blocks[i].weight, blocks[i].solid) >= 0)
                    dp[i][w] = max(dp[i][w], dp[i - 1][min(w - blocks[i].weight, blocks[i].solid)] + blocks[i].value);
            }
            if (i == 0 && w == blocks[i].weight)
            {
                dp[i][w] = blocks[i].value;
            }
            ret = max(ret, dp[i][w]);
        }
    }
    cout << ret << endl;
}