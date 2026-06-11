#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define P pair<ll, ll>

int main(){
    ll n, k;
    cin >> n >> k;
    priority_queue<P> que1;
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        t--;
        que1.push(P(d, t));
    }
    ll a[n];
    rep(i, n) a[i] = 0;
    ll num = 0;
    ll ans = 0;
    priority_queue<P, vector<P>, greater<P> > que2;
    for (int i = 0; i < k; i++){
        P p = que1.top();
        que1.pop();
        if(a[p.second] == 0) num++;
        a[p.second]++;
        ans += p.first;
        que2.push(p);
    }
    ans += num * num;
    ll sm = ans;
    for (int i = num + 1; i <= k; i++){
        
        while (!que1.empty()){
            P p1 = que1.top();
            que1.pop();
            if (a[p1.second] != 0) continue;
            P p2;
            while(true){
                p2 = que2.top();
                que2.pop();
                if(a[p2.second] > 1){
                    a[p2.second]--;
                    break;
                }
            }
            a[p1.second]++;
            sm = sm - p2.first - (i - 1) * (i - 1) + p1.first + (i * i);
            break;
        }
        ans = max(ans, sm);
    }
    cout << ans << endl;
}

