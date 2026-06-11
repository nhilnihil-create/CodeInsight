#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> V;
void input()
{
    V.resize(3);
    cin >> V[0] >> V[1] >> V[2];
}

void solve()
{
    sort(V.begin(),V.end());

    int cnt = 0;
    cnt += (V[2] - V[0]) / 2;
    V[0] += (V[2] - V[0]) / 2 * 2;
    cnt += (V[2] - V[1]) / 2;
    V[1] += (V[2] - V[1]) / 2 * 2;

    if (V[2] - V[0] == 0 && V[2] - V[1] == 0) cout << cnt << endl;
    else if (V[2] - V[0] == 1 && V[2] - V[1] == 1) cout << cnt + 1 << endl;
    else  cout << cnt + 2 << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}