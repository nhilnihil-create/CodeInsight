#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<pair<lli, lli>> d(n);
    lli y = 0;
    rep(i, n){
        lli a, b;
        cin >> a >> b;
        d[i] = {a, b};
        y+=b;
    }
    sort(d.begin(), d.end(), [](const pair<lli, lli> &x, const pair<lli, lli> &y){
        if(x.first+x.second > y.first+y.second) return true;
        else return false;
    });
    lli x = 0;
    rep(i, n){
        if(i%2==0) x+=d[i].first+d[i].second;
    }
    cout << x-y << endl;
    return 0;
}
