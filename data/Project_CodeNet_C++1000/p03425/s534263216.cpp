#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0;i < n;i++){
        cin >> s[i];
    }
    ll m = 0,a = 0,r = 0,c = 0,h = 0;

    for (ll i = 0; i < n; i++){
        if (s[i][0] == 'M'){
            m++;
            continue;
        }
        if (s[i][0] == 'A'){
            a++;
            continue;
        }
        if (s[i][0] == 'R'){
            r++;
            continue;
        }
        if (s[i][0] == 'C'){
            c++;
            continue;
        }
        if (s[i][0] == 'H'){
            h++;
            continue;
        }
    }

    ll ans = m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
    cout << ans << endl;
    
}