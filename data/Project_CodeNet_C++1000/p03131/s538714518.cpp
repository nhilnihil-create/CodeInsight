#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(ll K, ll A, ll B, ll &ans){

    ll ans_buf;
    ll plus_dif = B - A;

    if(plus_dif <= 1) ans_buf = 1 + K;
    else{
        ll num_buf;
        num_buf = K - (A - 1);
        ans_buf = A;

        if(num_buf%2 == 0) ans_buf += plus_dif*(num_buf/2);
        else ans_buf += plus_dif*(num_buf/2) + 1;
    }
    ans = ans_buf;

    return;
}

int main(){

    ll K, A, B;
    cin >> K >> A >> B;

    ll ans;
    solver(K, A, B, ans); 

    cout << ans << endl;

    return 0;
}
