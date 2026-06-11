#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(5);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s[0]=='M'){
            a[0]++;
        }
        if(s[0]=='A'){
            a[1]++;
        }
        if(s[0]=='R'){
            a[2]++;
        }
        if(s[0]=='C'){
            a[3]++;
        }
        if(s[0]=='H'){
            a[4]++;
        }
    }

    ll ans=0;
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 4; j++) {
            for(int k = j+1; k < 5; k++) {
                ans += a[i]*a[j]*a[k];
            }
        }
    }

    cout << ans << endl;

    return 0;
}