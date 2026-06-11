#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    ll m_num = 0;
    ll a_num = 0;
    ll r_num = 0;
    ll c_num = 0;
    ll h_num = 0;
  
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s[0] == 'M') m_num++;
        if (s[0] == 'A') a_num++;
        if (s[0] == 'R') r_num++;
        if (s[0] == 'C') c_num++;
        if (s[0] == 'H') h_num++;
    }

    ll ans = 0;
    ans += m_num * a_num * r_num;
    ans += m_num * a_num * c_num;
    ans += m_num * a_num * h_num;    

    ans += m_num * r_num * c_num;
    ans += m_num * r_num * h_num;
    ans += m_num * c_num * h_num;

    ans += a_num * r_num * c_num;
    ans += a_num * r_num * h_num;
    ans += a_num * c_num * h_num;
    
    ans += r_num * c_num * h_num;

    cout << ans << endl;
    return 0;
}