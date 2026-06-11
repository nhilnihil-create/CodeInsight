#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<pair<ll,ll>> sa, ba;
    ll sum = 0;
    ll nin = 1e9 * 2; 
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        sum += a;
        if(a <= b)sa.emplace_back(a,b);
        else ba.emplace_back(a,b);
    }

    if((int)sa.size() == n) {
        cout << 0 << endl;
        return 0;
    }

    for(auto i : ba) {
        nin = min(nin, i.second);
    }

    cout << sum - nin << endl;



}