#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> d;
    vector<ll> a(n);
    rep(i, 0, n)cin >> a[i];
    vector<ll> b(n);
    rep(i, 0, n)cin >> b[i];
    int count = 0;
    ll p = 0, sum = 0;
    rep(i, 0, n){
        ll dif = a[i]-b[i];
        sum += dif;
        d.push_back(dif);
        if(dif < 0){
            count++;
            p += (-1)*dif;
        }
    }
    if(count == 0){
        cout << "0" << endl;
        return 0;
    }
    if(sum < 0){
        cout << "-1" << endl;
        return 0;
    }
    int c;
    sort(d.begin(), d.end(), greater<ll>());
    rep(i, 0, n){
        p -= d[i];
        if(p <= 0){
            c = i+1;
            break;
        }
    }
    cout << count + c << endl;
}