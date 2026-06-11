#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    rep(i, n)
    {
        cin >> nums[i];
    }
    // 正の座標を優先的に取得する
    int mini = INF;
    for (int i = 0; i <= n - k; i++)
    {
        int total = 0;
        if (nums[i] < 0)
        {
            total += abs(nums[i]) * 2;
        }
        else
        {
            total += nums[i];
        }

        if (nums[i + k - 1] < 0)
        {
        }
        else
        {
            total += nums[i + k - 1];
            if (nums[i] > 0)
            {
                total -= nums[i];
            }
        }

        mini = min(mini, total);
    }
    // 負の数を優先的に取得する
    for (int i = 0; i <= n - k; i++)
    {
        int total = 0;

        if (nums[i + k - 1] < 0)
        {
            total += abs(nums[i + k - 1]);
        }
        else
        {
            total += nums[i + k - 1] * 2;
        }
        if (nums[i] > 0)
        {
        }
        else
        {
            total += abs(nums[i]);
            if (nums[i + k - 1] < 0)
            {
                total -= abs(nums[i + k - 1]);
            }
        }
        mini = min(mini, total);
    }
    cout << mini << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
