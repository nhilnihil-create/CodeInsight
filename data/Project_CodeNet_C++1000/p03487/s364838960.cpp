#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

const ll M = 1e9 + 1;

int main(void)
{
    int N;
    cin >> N;

    unordered_map<int, int> order;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        order[num]++;
    }

    int ans = 0;
    for (auto itr = order.begin(); itr != order.end(); itr++)
    {
        // cout << itr->first << " : " << itr->second << endl;
        auto key = itr->first;
        auto value = itr->second;

        if (key < value)
        {
            ans += value - key;
        }
        else if (key > value)
        {
            ans += value;
        }
    }
    cout << ans << endl;
    return (0);
}