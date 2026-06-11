#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const int INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool CompPair(const pint& arg1, const pint& arg2) { return arg1.second < arg2.second; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> c(10, vector<int>(10));
    vector<vector<int>> a(h, vector<int>(w));
    for(int in=0;in<10;in++) {
        for(int jn=0;jn<10;jn++) {
            cin >> c.at(in).at(jn);
        }
    }
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> a.at(ih).at(iw);
        }
    }

    for(int k=0;k<10;k++) {
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                if(c.at(i).at(j)>c.at(i).at(k)+c.at(k).at(j)) {
                    c.at(i).at(j)=c.at(i).at(k)+c.at(k).at(j);
                }
            }
        }
    }

    int ans = 0;
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            if(a.at(ih).at(iw)==-1) continue;
            else ans += c.at(a.at(ih).at(iw)).at(1);
        }
    }
    cout << ans << endl;
    return 0;
}
