#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int main()
{
    int n;
    cin >> n;

    // 0番目を確認する
    string zero;
    cout << 0 << endl;
    cin >> zero;

    int flag;
    if (zero == "Vacant")
    {
        return 0;
    }

    int left = 0;
    int right = n;
    while (right - left > 0)
    {
        int mid = (left + right) / 2;
        string resp;
        cout << mid << endl;
        cin >> resp;
        if (mid % 2 == 1)
        {
            if (resp == "Vacant")
            {
                return 0;
            }
            else if (resp == zero)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        else
        {
            if (resp == "Vacant")
            {
                return 0;
            }
            else if (resp == zero)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }
}