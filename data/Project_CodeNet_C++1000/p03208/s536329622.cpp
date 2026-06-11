#include<bits/stdc++.h>
using namespace std;
int main(){
        int n, k; cin >> n >> k;
        vector<int> v;
        for (int x = 0; x < n; ++x){
            int q; cin >> q;
            v.push_back(q);
        }
        sort(v.begin(), v.end(), greater<int>());
        int mn = INT_MAX;
        for (int x = 0; x < v.size() - (k-1); ++x){
            mn = min(mn, v[x] - v[x + (k - 1)]);
        }
        cout << mn << endl;
    return 0;
}
