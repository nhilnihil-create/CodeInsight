#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n;
    cin >> n;
    
    vector<long> a(n);
    for(auto &x: a) cin >> x;

    map<long,long> m;
    for(auto &x: a) {
        m[x] = m[x] + 1;
    }

    long r = 0;
    for(long i=1l<<40; i; i>>=1) {
        for(auto &t: m) {
            if(t.second == 0) continue;
            if(i - t.first == t.first) {
                long k = t.second / 2;
                m[t.first] -= k*2;
                r += k;
            }
            else if(m.count(i - t.first) == 1 && m[i - t.first] > 0) {
                long k = min(t.second, m[i-t.first]);
                m[t.first] -= k;
                m[i - t.first] -= k;
                r += k;
            }
        }
    }
    cout << r << endl;
}
