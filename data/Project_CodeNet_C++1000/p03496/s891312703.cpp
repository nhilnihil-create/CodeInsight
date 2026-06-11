#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int amax = 0, amin = 0;
    rep(i, n){
        cin >> a[i];
        if(a[i] < a[amin]){
            amin = i;
        }
        if(a[i] > a[amax]){
            amax = i;
        }
    }
    vector<vector<int>> operations;
    if (abs(a[amax]) >= abs(a[amin])) {
        rep(i,n){
            if(i == amax) continue;
            operations.push_back({amax, i});
        }
        for(int i = 0; i < n-1; i++) operations.push_back({i, i + 1});
    } else {
        rep(i,n){
            if(i == amin) continue;
            operations.push_back({amin, i});
        }
        for(int i = n-1; i > 0; i--) operations.push_back({i, i-1});
    }

    cout << operations.size() << endl;
    for(auto v : operations){
        cout << v[0]+1 << " " << v[1]+1 << endl;
    }
}