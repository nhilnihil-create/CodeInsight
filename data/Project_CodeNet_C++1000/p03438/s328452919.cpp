#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n){
        if(a[i] > b[i]) d[i]+=a[i]-b[i];
        else if(a[i] < b[i]){
            if(a[i]%2 != b[i]%2){
                d[i]++;
            }
            c[i]+=((b[i]+d[i])-a[i])/2;
        }
    }
    lli sc, sd;
    sc = sd = 0;
    rep(i, n){
        sc+=c[i], sd+=d[i];
    }
    if(sc >= sd) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
