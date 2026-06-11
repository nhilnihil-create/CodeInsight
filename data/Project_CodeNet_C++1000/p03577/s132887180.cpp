#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    string S;
    cin >> S;
    for(int i = 0, i_len = S.size() - 8; i < i_len; ++i) cout << S[i];
    cout << endl;
    return 0;
}