#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    int N;
    cin >> N;
    set<int> D;
    rep(i, 0, N)
    {
        int tmp;
        cin >> tmp;
        D.insert(tmp);
    }
    cout << D.size() << endl;
}