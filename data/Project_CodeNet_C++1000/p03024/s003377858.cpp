#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    string S;
    cin >> S;
    int len = S.size();
    int win = 0;
    for(int i = 0, i_len = S.size(); i < i_len; ++i) if(S[i] == 'o') ++win;
    if(15 - len >= 8 - win) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}