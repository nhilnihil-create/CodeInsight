#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    ll n; cin >> n;
    vector<ll> t(100001),x(100001),y(100001),s(100001);
    bool f = true;

    rep(i,n){
        cin >> t[i] >> x[i] >> y[i];
        s[i] = x[i] + y[i];
    }

    rep(i,n){
        if(i == 0) {
            if (t[i] < s[i]) f = false;
            else if (t[i] > s[i] && (t[i] - s[i]) % 2 == 1) f = false;
        }else{
            if (t[i]-t[i-1]  < abs(s[i]-s[i-1])) f = false;
            else if (t[i]-t[i-1] > abs(s[i]-s[i-1]) && (t[i]-t[i-1] - abs((s[i]-s[i-1]))) % 2 == 1) f = false;
        }
    }

    cout << ((f)?"Yes":"No");


    return 0;
}









