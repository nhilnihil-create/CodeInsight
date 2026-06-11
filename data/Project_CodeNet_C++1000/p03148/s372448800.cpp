/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.19 00:48:48
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n,k;cin >> n >> k;
    typedef pair<int,int> T;
    priority_queue<T> pq1;
    priority_queue<T,vector<T>,greater<T>> pq2;
    for (int i = 0; i < n; i++) {
        int t,d;cin >> t >> d;
        t--;
        pq1.push(make_pair(d,t));
    }
    ll sum = 0;
    ll kind_cnt = 0;
    vector<bool> kind(n,false);
    for (int i = 0; i < k; i++) {
        auto p = pq1.top(); pq1.pop();
        sum += p.first;
        if (!kind[p.second]) {
            kind[p.second] = true;
            kind_cnt++;
        }
        else {
            pq2.push(p);
        }
    }
    ll ans = kind_cnt * kind_cnt + sum;
    while(!pq2.empty()) {
        auto p = pq2.top(); pq2.pop();
        sum -= p.first;
        while(!pq1.empty() && kind[pq1.top().second]) {
            pq1.pop();
        }
        if (pq1.empty()) break;
        p = pq1.top(); pq1.pop();
        kind[p.second] = true;
        kind_cnt++;
        sum += p.first;
        ans = max(ans,kind_cnt * kind_cnt + sum);
    }
    cout << ans << endl;
    return 0;
}