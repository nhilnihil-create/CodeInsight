#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int d,g;
    cin >> d >> g;
    vector<int>p(d);
    vector<int>c(d);
    rep(i,d) cin >> p[i] >> c[i];
    ll res = 1001001001;
    for(int bit = 0; bit < (1<<d);bit++) {
        ll sum = 0;
        ll cnt = 0;
        for(int i = 0;i<d;i++) {
            if(bit & 1<<i) {
                sum += p[i]*(i+1)*100+c[i];
                cnt += p[i];
            }
        }
        if(sum>=g) {
            res = min(res,cnt);
        } else {
            for(int j = d-1;j>=0;j--) {
                if(bit & (1<<j)) continue;
                for(int k = 0;k<p[j];k++) {
                    if(sum>=g) break;
                    sum += (j+1)*100;
                    cnt++;
                }
            }
        }
        res = min(res,cnt);
    }
    cout << res << endl;
}
