#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N;

int main()
{
    cin >> N;
    vector<pair<pair<string, int>, int>> rest(N);
    string s;
    int a;
    rep(i, 0, N)
    {
        cin >> s >> a;
        rest[i].first = make_pair(s, -a);
        rest[i].second = i;
    }
    sort(rest.begin(), rest.end());
    rep(i, 0, N)
    {
        cout << rest[i].second + 1 << endl;
    }
    return 0;
}
