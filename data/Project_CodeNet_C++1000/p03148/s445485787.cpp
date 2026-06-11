#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long n, k;
    cin >> n >> k;
    
    vector<pair<long,long>> v(n);
    for(auto &e: v) cin >> e.second >> e.first;
    for(auto &e: v) e.first *= -1;
    sort(v.begin(), v.end());
    for(auto &e: v) e.first *= -1;

    long r = 0, rr = 0;
    set<long> s;
    map<long,long> mi;
    map<long,long> cnt;
    {
        for(int i=0; i<k; i++) {
            rr += v[i].first;
            s.insert(v[i].second);
            cnt[v[i].second]++;
        }
        r = rr + s.size()*s.size();
    }

    {
        int j = k-1;
        for(int i=k; i<n; i++) {
            if(s.count(v[i].second) == 0) {
                while(j >= 0 && cnt[v[j].second] == 1) j--;
                if(j < 0) break;

                s.insert(v[i].second);
                rr -= v[j].first;
                rr += v[i].first;
                r = max(r, rr + (long)(s.size()*s.size()));

                j--;
            }
        }
    }

    cout << r << endl;
}
