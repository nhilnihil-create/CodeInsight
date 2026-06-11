#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

vector<int> L;
int N, A, B, C;
const int INF = 1 << 30;
int rec(int index, int a, int b, int c)
{
    if (N == index)
    {
        if (!a || !b || !c)
        {
            return INF;
        }
        else
        {
            return abs(A - a) + abs(B - b) + abs(C - c);
        }
    }
    int res = rec(index + 1, a, b, c);
    res = min(res, rec(index + 1, a + L[index], b, c) + (a ? 10 : 0));
    res = min(res, rec(index + 1, a, b + L[index], c) + (b ? 10 : 0));
    res = min(res, rec(index + 1, a, b, c + L[index]) + (c ? 10 : 0));
    return res;
}

int main()
{
    cin >> N >> A >> B >> C;

    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        L.push_back(l);
    }

    cout << rec(0, 0, 0, 0) << endl;

    return 0;
}