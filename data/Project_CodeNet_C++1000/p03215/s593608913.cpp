#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint n, k;
    cin >> n >> k;

    vector<lint> a(n);
    for(auto& elem : a)  cin >> elem;

    partial_sum(begin(a), end(a), begin(a));
    a.insert(begin(a), 0);

    vector<lint> x;
    for(lint left=0; left<n; left++) {
        for(lint right=left+1; right<=n; right++) {
            x.push_back(a[right] - a[left]);
        }
    }

    bitset<60> ans;
    for(lint d=59; d>=0; d--) {
        vector<lint> cand;
        for(lint i=0; i<x.size(); i++) {
            bitset<60> bs(x[i]);
            if(bs.test(d))  cand.push_back(x[i]);
        }

        if(cand.size() >= k) {
            ans.set(d);
            x = cand;
        }
    }

    cout << ans.to_ullong() << endl;
}