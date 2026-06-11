#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, M, X;
    cin >> N >> M >> X; 
    vector<ll> A(M);
    rep(i,M) cin >> A[i];

    ll up = 0;
    ll down = 0;
    rep(i,M) {
        if(A[i] > X) up++;
        else down++;
    }
    cout << min(up, down) << endl;
}


