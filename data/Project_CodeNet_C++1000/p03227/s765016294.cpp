#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

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

int main()
{
    string s;
    cin >> s;
    if (s.size() == 2)
    {
        cout << s << endl;
    }
    else
    {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}
