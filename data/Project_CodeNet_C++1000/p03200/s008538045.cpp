#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    long cnt=0;
    long bcnt=0, cnt1=0, cnt2=0;
    rep(i,s.size()) {
        if (s.at(i)=='B') {
            bcnt++;
            cnt1 += i;
        }
    }
    for (long i=s.size()-bcnt; i<s.size(); ++i) {
        cnt2 += i;
    }

    cout << cnt2 - cnt1 << endl;
    return 0;
}