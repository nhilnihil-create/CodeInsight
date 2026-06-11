#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 互除法で2正数x,yのgcdを返す関数
ll gcd (ll x, ll y) {
    ll p = x % y;
    while(p){
        x = y;
        y = p;
        p = x % y;
    }
    return y;
}

int main() {
    int Q;
    cin >> Q;
    vector<int>ans(Q);
    for (int i = 0; i < Q; ++i) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if(A < B || B > D) {
            ans[i] = 0;
            continue;
        }
        if(C >= B){
            ans[i] = 1;
            continue;
        }
        if(A > C) {
            A = A - B * ((A - (C + 1)) / B);
        } else{
            A += D;
            if(D != B) A = A + (D - B) * ((C - A) / (D - B) + 1);
        }
        ll gcd_B_D = gcd(B, D);
        A = A - gcd_B_D * ((A - (C + 1)) / gcd_B_D);
        if(A >= B){
            ans[i] = 1;
        } else{
            ans[i] = 0;
        }
    }
    for (int i = 0; i < Q; ++i) {
        if(ans[i]){
            cout << "Yes" << "\n";
        } else{
            cout << "No" << "\n";
        }
    }
    return 0;
}