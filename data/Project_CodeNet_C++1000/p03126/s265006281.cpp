#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(ll i = k; i < (ll)(n); i++)
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m, 0);
    rep(i, 0, n){
        int k;
        cin >> k;
        rep(j, 0, k){
            int f;
            cin >> f;
            cnt[f-1] ++; 
        }
    }
    int food = 0;
    for (auto c:cnt){
        if (c == n) food ++; 
    }    
    cout << food << endl;
}