#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int N;
    cin >> N;
    int ans = 0;
    xrep(n1, 1, N+1) {
        int cnt = 0;
        xrep(n2, 1, N+1) {
            if(n1%n2==0 && n1%2==1) {
                ++cnt;
            }
        }
        if(cnt==8) ++ans;
    }
    cout << ans << endl;

    return 0;
}