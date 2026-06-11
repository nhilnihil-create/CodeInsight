#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<int> a(N), b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];
    ll ans = 0;
    REP(i,29) {
        int cnt = 0;
        vector<int> b1, b2;
        REP(j,N) {
            if((b[j]>>i)&1) b1.push_back((b[j]&((1<<i)-1)));
            else b2.push_back((b[j]&((1<<i)-1)));
        }
        sort(all(b1));
        sort(all(b2));
        REP(j,N) {
            int x = (a[j]&((1<<i)-1)); 
            if((a[j]>>i)&1) {
                int t1 = b1.end() - lower_bound(all(b1),(1<<i)-x);
                int t2 = lower_bound(all(b2),(1<<i)-x) - b2.begin();
                cnt = (cnt+t1+t2)%2;
            }
            else {
                int t1 = lower_bound(all(b1),(1<<i)-x) - b1.begin();
                int t2 = b2.end() - lower_bound(all(b2),(1<<i)-x);
                cnt = (cnt+t1+t2)%2;
            }
        }
        // cout << cnt << endl;
        if(cnt) ans |= (1LL<<i);
    }
    //REP(i,10) cout << (15&((1<<i)-1)) << ' '; cout << endl;
    cout << ans << endl;
    return 0;
}