#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    string s;
    cin >> s;
    int maxi = 0;
    int seq = 0;
    for (char c : s)
    {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T')
        {
            ++seq;
        }
        else
        {
            maxi = max(seq, maxi);
            seq = 0;
        }
    }
    maxi = max(seq, maxi);
    cout << maxi << endl;
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