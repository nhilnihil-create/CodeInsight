#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    string S;
    cin >> S;

    // 26文字でない場合は未使用の文字を末尾に追加
    // 26文字の場合は後ろから読んで下がったところで切り上げ
    if (S.size() != 26)
    {
        vector<int> cnt(26, 0);
        for (char c : S)
        {
            cnt[c - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
            {
                cout << S << char('a' + i) << endl;
                return 0;
            }
        }
    }
    if (S == "zyxwvutsrqponmlkjihgfedcba")
    {
        cout << -1 << endl;
        return 0;
    }
    string T = S;
    next_permutation(S.begin(), S.end());
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == T[i])
        {
            cout << S[i];
            continue;
        }
        cout << S[i] << endl;
        return 0;
    }
    cout << S << endl;
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
