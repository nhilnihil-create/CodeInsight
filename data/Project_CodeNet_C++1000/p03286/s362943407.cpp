#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll N, set<ll>& res){
    if(N==0) return;

    ll n = 0;
    ll s = N / abs(N);
    for(ll i=0; i<16; i++){
        auto j = 2 * i;
        if(N < 0) j++;
        n += ((ll)1) << j;
        if(abs(N) <= n){
            N -= s * ((ll)1 << j);
            res.insert(j);;
            solve(N, res);
            return;
        }
    }
}

int main()
{
    ll N;
    cin >> N;
    set<ll> digits;
    solve(N, digits);
    string res;
    for(int i=0; i<32; i++){
        if(digits.count(i)) res += '1';
        else                res += '0';
    }
    while(res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    if(res == "") res = "0";
    cout << res << endl;

    return 0;
}