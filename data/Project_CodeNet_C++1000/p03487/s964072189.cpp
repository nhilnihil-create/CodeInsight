#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    map<int, int> sequence;
    int tmp;
    rep(i, n)
    {
        cin >> tmp;
        sequence[tmp]++;
    }
    int cnt = 0;
    for (auto itr = sequence.begin(); itr != sequence.end(); itr++)
    {
        if (itr->first < itr->second)
        {
            cnt += itr->second - itr->first;
        }
        else if (itr->first > itr->second)
        {
            cnt += itr->second;
        }
    }
    cout << cnt << endl;
    return 0;
}