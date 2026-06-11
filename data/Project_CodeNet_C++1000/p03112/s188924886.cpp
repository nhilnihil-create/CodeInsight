#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s, t;

    s.push_back(ll(-10e10));
    t.push_back(ll(-10e10));
    for(int i = 0; i < a; i++){
        ll tmp; cin >> tmp;
        s.push_back(tmp);
    }
    for(int i = 0; i < b; i++){
        ll tmp; cin >> tmp;
        t.push_back(tmp);
    }
    s.push_back(ll(20e10));
    t.push_back(ll(20e10));

    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        vector<ll> temple(2);
        vector<ll> shrine(2);

        auto t_itr = lower_bound(t.begin(), t.end(), x);
        temple[1] = *t_itr;
        t_itr--;
        temple[0] = *t_itr;
        // cout << temple[0] << " " << temple[1] << endl;

        auto s_itr = lower_bound(s.begin(), s.end(), x);
        shrine[1] = *s_itr;
        s_itr--;
        shrine[0] = *s_itr;
        // cout << shrine[0] << " " << shrine[1] << endl;

        ll ans = ll(30e10);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                ans = min(ans, abs(x - shrine[i]) + abs(shrine[i] - temple[j]));
                ans = min(ans, abs(x - temple[j]) + abs(shrine[i] - temple[j]));
            }
        }

        cout << ans << endl;
    }
    return 0;
}