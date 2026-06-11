#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, k, q;
    cin >> n >> k >> q;
    vector<long> a(n);
    for(auto &e: a) cin >> e;

    vector<long> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    set<long> bads;
    bads.insert(-1);
    bads.insert(n);

    long r = 1e18;

    for(long mi: b) {
        vector<long> v;

        auto it = bads.begin();
        auto is = it++;
        while(it != bads.end()) {
            vector<long> w;
            // (is, it)
            long cnt = (*it-1 +1) - (*is+1);
            if(cnt-k+1 > 0) {
                copy(a.begin()+(*is+1), a.begin()+(*it-1 +1), back_inserter(w));
                sort(w.begin(), w.end());
                copy_n(w.begin(), cnt-k+1, back_inserter(v));
            }
            is = it++;
        }

        if(v.size() < q) break;
        sort(v.begin(), v.end());
        r = min(r, v[q-1] - v[0]);

        for(long i=0; i<n; i++)
            if(a[i] == mi) bads.insert(i);
    }

    cout << r << endl;

}
