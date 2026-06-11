#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    int edge1 = X;
    int edge2 = Y;
    rep(0, i, N)
    {
        int x;
        cin >> x;
        edge1 = max(edge1, x);
    }
    rep(0, i, M)
    {
        int y;
        cin >> y;
        edge2 = min(edge2, y);
    }
    if (edge1 < edge2)
    {
        cout << "No War" << endl;
    }
    else
    {
        cout << "War" << endl;
    }
}