#include<bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

int main() {
    int N; cin >> N;
    vector<pint> res;
    int dame = N;
    if(N % 2 == 1) --dame;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(j <= i || j == dame) continue;
            res.push_back(pint(i, j));
        }
        --dame;
    }

    cout << res.size() << endl;
    for (auto p : res)
    {
        cout << p.first << " " << p.second << endl;
    }

}