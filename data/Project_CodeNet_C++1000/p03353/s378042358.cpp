#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string s;
    int K;
    cin >> s >> K;
    int size = s.size();
    map<string, ll> mp;
    rep(1, i, 6)
    {
        rep(0, j, size - i + 1)
        {
            string sub = s.substr(j, i);
            mp[sub];
        }
    }
    int k = 1;
    for (auto m : mp)
    {
        if (k == K)
        {
            cout << m.first << endl;
        }
        k++;
    }
}