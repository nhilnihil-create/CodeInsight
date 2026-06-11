#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    deque<int> c;
    int cnt = 0;
    rep(j,n) {
        int id = n-1-j;
        //cout << "id "<<id << endl;
        rrep(i,n) {
            if(b[i]==-1) continue;
            if(b[i]==id+1) {
                b[i]=-1;
                c.push_front(id+1);
                cnt++;
                break;
            }
            id--;
        }
    }
    if(cnt!=n) cout << -1 << endl;
    else {
        rep(i,n)cout << c[i] << endl;
    }
    return 0;
}

