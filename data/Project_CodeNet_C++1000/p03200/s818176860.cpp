#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    string s; cin >> s;
    ll ans = 0;
    ll countB = 0;

    for(ll i = s.length()-1; i >=0; i --){
        if(s[i] == 'B'){
            ans += (s.length() -1 - i -countB);
            countB ++;
        }
    }

    cout << ans;

    return 0;
}









