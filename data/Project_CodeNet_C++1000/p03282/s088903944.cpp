#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll gosen = 5000000000000000;

int main() {
    string S; cin >> S;
    ll K; cin >> K;
    ll s = S.size();
    ll cnt = 0;
    ll a;
    rep(i, s){
        cnt++;
        a = S[i] - '0';
        if(a != 1){
            break;
        }
    }
    if(K < cnt){
        cout << 1 << endl;
    } else {
        cout << a << endl;
    }

    return 0;
}