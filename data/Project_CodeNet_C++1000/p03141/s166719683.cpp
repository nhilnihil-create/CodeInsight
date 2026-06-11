#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)


//  1 1000
// 50 50
// 
// 1000 10
// 1    1000
//
// 1000 - 1000
// 1 - 10

int main() {
    int n; cin >> n;
    pair<int,int> ab[100000];
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    pair<int,int> cand[100000];
    rep(i,n) {
        cand[i] = make_pair(ab[i].first + ab[i].second, i);
    }
    sort(cand, cand+n, greater<pair<int,int>>());
    lint takahasi = 0;
    lint aoki = 0;
    rep(i,n) {
        if (i % 2 == 0) takahasi += ab[cand[i].second].first;
        else aoki += ab[cand[i].second].second;
    }
    cout << takahasi - aoki << endl;

}