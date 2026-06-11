#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<pair<ll, ll>> secl, secr;
    for (int i = 0; i < N; i++) {
        ll L, R;
        cin >> L >> R;
        secl.push_back({L, R});
        secr.push_back({R, L});
    }
    
    sort(secl.begin(), secl.end());
    sort(secr.begin(), secr.end());
    for (int i = 0; i < N; i++) {
        swap(secr[i].first, secr[i].second);
    }
    
    int M = N/2;
    ll cand = 0;
    ll now = 0;
    
    for (int i = 0; i < M; i++) {
        if (secl[N-1-i].first <= now) {
            cand += abs(now);
            now = 0;
            break;
        }
        cand += secl[N-1-i].first-now;
        now = secl[N-1-i].first;
        if (now <= secr[i].second) {
            cand += abs(now);
            now = 0;
            break;
        }
        cand += now-secr[i].second;
        now = secr[i].second;
        if (i == M-1 && M%2 == 1 && now < secl[N-2-i].first) {
            cand += secl[N-2-i].first-now;
            now = secl[N-2-i].first;
            cand += abs(now);
            now = 0;
        }
    }
    
    ll ans = cand;
    cand = 0;now = 0;
    
    for (int i = 0; i < M; i++) {
        if (now <= secr[i].second) {
            cand += abs(now);
            now = 0;
            break;
        }
        cand += now-secr[i].second;
        now = secr[i].second;
        
        if (secl[N-1-i].first <= now) {
            cand += abs(now);
            now = 0;
            break;
        }
        cand += secl[N-1-i].first-now;
        now = secl[N-1-i].first;
        
        if (i == M-1 && M%2 == 1 && secr[i+1].second < now ) {
            cand += now-secr[i+1].second;
            now = secr[i+1].second;
            cand += abs(now);
            now = 0;
        }
    }
    ans = max(ans, cand);
    cout << ans << endl;
    return 0;
}
