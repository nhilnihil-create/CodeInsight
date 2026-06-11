#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    int X, Y; cin >> X >> Y;

    cout << (X % Y == 0 ? -1 : X) << endl;
}
