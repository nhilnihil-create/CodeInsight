#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, v;
    cin >> n;
    map<int,int> odd, even;
    vector<P> oddmax(2, P(0,0)), evenmax(2, P(0,0));
    rep(i,n/2) {
        cin >> v;
        ++odd[v];
        cin >> v;
        ++even[v];
    }
    for (auto x : odd) {
        if (x.second > oddmax.at(0).first) {
            oddmax.at(0).first = x.second;
            oddmax.at(0).second = x.first;
            sort(oddmax.begin(), oddmax.end());
        }
    }
    for (auto x : even) {
        if (x.second > evenmax.at(0).first) {
            evenmax.at(0).first = x.second;
            evenmax.at(0).second = x.first;
            sort(evenmax.begin(), evenmax.end());
        }
    }
    if (oddmax.at(1).second != evenmax.at(1).second) {
        cout << n - oddmax.at(1).first - evenmax.at(1).first << endl;
    } else {
        cout << n - max(oddmax.at(1).first + evenmax.at(0).first, oddmax.at(0).first + evenmax.at(1).first) << endl;
    }
}
