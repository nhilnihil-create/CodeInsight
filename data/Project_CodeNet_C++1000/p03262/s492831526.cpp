#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)
template <class T>
T calcgcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y); //小さい方をyとする
    }
    T r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> dist(N);
    REP(i, N)
    {
        int c;
        cin >> c;
        c -= X;
        if (c < 0) c = -c;
        dist[i] = c;
    }

    for (int i = 1; i < N; ++i)
    {
        dist[i] = calcgcd<int>(dist[i], dist[i - 1]);
    }
    cout << dist[N - 1] << endl;
    return 0;
}
