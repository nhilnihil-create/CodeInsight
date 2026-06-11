#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    string S;
    cin >> S;
    string T = "keyence";
    int samebegin = 0;
    int sameend = 0;
    rep(i,T.size()) {
        if (S.at(i) != T.at(i)) break;
        else ++samebegin;
    }
    rep(i,T.size()) {
        if (S.at(S.size() - 1 - i) != T.at(T.size() - 1 - i)) break;
        else ++sameend;
    }
    if (samebegin + sameend >= T.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
