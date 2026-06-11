#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> v;
    long long k;
    for (int i = 0; i < n; i++) {
        cin>>k;
        if (k % 2 == 0) v.push_back(k);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int nextIndex = 0;
    while (true) {
        bool evenUsed = false;
        for (int i = nextIndex; i < v.size(); i++) {
            if (v[i] % 2 == 0 && !evenUsed) {
                v[i] /= 2;
                if (v[i] % 2 == 1) nextIndex++;
                evenUsed = true;
            } else {
                v[i] *= 3;
            }
        }
        if (evenUsed == false) break;
        ans++;
    }
    cout<<ans<<endl;
}