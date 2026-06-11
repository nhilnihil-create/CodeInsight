#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    // 空席を挟む場合
    //  r-lが偶数なら r,lは異性になる
    // r-l が奇数なら、r,lは同棲になる。
    int left = 0;
    string ls;

    int right = N-1;
    string rs;

    string v = "Vacant";
    string m = "Male";
    string f = "Female";

    cout << left << endl;
    cin >> ls;

    if(ls == v) {
        return;
    }

    cout << right << endl;
    cin >> rs;

    if(rs == v) {
        return;
    }

    while(true) {
        int mid = (left+right)/2;
        cout << mid << endl;
        string ms;
        cin >> ms;
        if(ms == v) {
            return;
        }
        // left and mid check
        bool lm = ls == ms;
        int oe = ((mid-left)%2);
        if((oe == 0 && !lm) || (oe  == 1 && lm)) {
            right = mid;
            rs = ms;
            continue;
        }

        // right and mid check
        bool rm = rs == ms;
        oe = ((right-mid)%2);
        if((oe == 0 && !rm) || (oe  == 1 && rm)) {
            left = mid;
            ls = ms;
            continue;
        }
    }
}

int main() {
    solve();
    return 0;
}