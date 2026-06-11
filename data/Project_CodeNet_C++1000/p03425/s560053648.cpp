#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i=0;i<n;i++){
        cin >> S[i];
    }
    map<char,ll> M;
    for(int i=0;i<n;i++){
        char ca = S[i][0];
        M[ca]++;
    }
    ll m = M['M'];
    ll a = M['A'];
    ll r = M['R'];
    ll c = M['C'];
    ll h = M['H'];
    ll ans = 0;
    ans += m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
    cout << ans << endl;

}