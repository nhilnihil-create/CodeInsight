#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b) {
    if ( a.first==b.first ) {
        return a.second < b.second;
    }
    return a.first>b.first;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<pair<int,int>> v(n);
    for ( int i=0; i<n; i++ ) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    int ans=0;
    vector<int> w;
    for ( int i=1; i<n; i++ ) {
        if ( v[i].second>=v[0].first ) {
            w.push_back(v[i].second);
        } 
    }
    sort(w.rbegin(), w.rend());
    for ( int i:w ) {
        if ( h>0 ) {
            h-=i;
            ans++;
        }
    }

    if ( h>0 && v[0].second>v[0].first ) {
        h-=v[0].second;
        ans++;
    }
    if ( h>0 ) {
        ans+=(h+v[0].first-1)/v[0].first;
    }
    cout << ans << '\n';
    return 0;
}