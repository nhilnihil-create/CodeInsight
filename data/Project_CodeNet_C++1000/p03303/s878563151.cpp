#include <bits/stdc++.h>
using namespace std;

signed main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    string S;
    int w;

    cin >> S >> w;

    for (int i = 0; i < S.size(); i += w) {
        cout << S[i];
    }
    cout << endl;
}
