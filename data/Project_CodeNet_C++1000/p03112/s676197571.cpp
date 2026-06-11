#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <deque>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int a,b,q;
    cin >> a >> b >> q;

    vector<ll> s(a);
    for(int i = 0;i < a;i++)cin >> s[i];

    vector<ll> t(b);
    for(int i = 0;i < b;i++)cin >> t[i];

    vector<ll> ans(q);
    for(int i = 0;i < q;i++){
        ll x;
        cin >> x;
        
        auto us = upper_bound(s.begin(),s.end(),x);
        auto ps = lower_bound(s.begin(),s.end(),x);

        auto ut = upper_bound(t.begin(),t.end(),x);
        auto pt = lower_bound(t.begin(),t.end(),x);

        ll d = 1e11;

        if(us != s.end() && ut != t.end())d = min(d,max(*us,*ut)-x);
        if(ps != s.begin() && pt != t.begin()){
            auto ds = ps;
            auto dt = pt;
            ds--,dt--;
            d = min(d,x-min(*ds,*dt));
        }
        if(ps != s.begin() && ut != t.end()){
            auto ds = ps;
            ds--;
            d = min(d,min(x-*ds,*ut-x)+*ut-*ds);
        }
        if(us != s.end() && pt != t.begin()){
            auto dt = pt;
            dt--;
            d = min(d,min(x-*dt,*us-x)+*us-*dt);
        }

        ans[i] = d;
    }


    for(int i = 0;i < q;i++)cout << ans[i] << endl;
}
