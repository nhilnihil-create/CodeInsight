#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> shrine(A + 2);
    vector<ll> temple(B + 2);
    vector<ll> x(Q);
    rep(i,A){
        cin >> shrine[i + 1];
    }
    shrine[0] = -10000000000000;
    shrine[A + 1] = 10000000000000;
    rep(i,B){
        cin >> temple[i + 1];
    }
    temple[0] = -10000000000000;
    temple[B + 1] = 10000000000000;
    rep(i,Q){
        cin >> x[i];
    }
    rep(i,Q){
        ll ans = 10000000000000;
        vector<ll>::iterator itr1 = lower_bound(all(shrine), x[i]);
        ll s1 = *itr1;
        ll s2 = shrine[itr1 - shrine.begin() - 1];
        ll ans1 = abs(x[i] - s1);
        ll ans2 = abs(x[i] - s1);
        ll ans3 = abs(x[i] - s2);
        ll ans4 = abs(x[i] - s2);
        vector<ll>::iterator itr2 = lower_bound(all(temple), s1);
        vector<ll>::iterator itr3 = lower_bound(all(temple), s2);
        ll s3 = *itr2;
        ll s4 = temple[itr2 - temple.begin() - 1];
        ll s5 = *itr3;
        ll s6 = temple[itr3 - temple.begin() - 1];
        ans1 += abs(s1 - s3);
        ans2 += abs(s1 - s4);
        ans3 += abs(s2 - s5);
        ans4 += abs(s2 - s6);
        
        ans = min(ans, min(ans1, min(ans2, min(ans3, ans4))));
        
        vector<ll>::iterator itr5 = lower_bound(all(temple), x[i]);
        ll s7 = *itr5;
        ll s8 = temple[itr5 - temple.begin() - 1];
        ll ans5 = abs(x[i] - s7);
        ll ans6 = abs(x[i] - s7);
        ll ans7 = abs(x[i] - s8);
        ll ans8 = abs(x[i] - s8);
        vector<ll>::iterator itr6 = lower_bound(all(shrine), s7);
        vector<ll>::iterator itr7 = lower_bound(all(shrine), s8);
        ll s9 = *itr6;
        ll s10 = shrine[itr6 - shrine.begin() - 1];
        ll s11 = *itr7;
        ll s12 = shrine[itr7 - shrine.begin() - 1];
        ans5 += abs(s7 - s9);
        ans6 += abs(s7 - s10);
        ans7 += abs(s8 - s11);
        ans8 += abs(s8 - s12);
        
        ans = min(ans, min(ans5, min(ans6, min(ans7, ans8))));
        
        cout << ans << endl;
    }
}
