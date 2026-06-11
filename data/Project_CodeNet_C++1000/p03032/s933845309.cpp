#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<long long> V(n);
    for(int i = 0; i < n; i++){
        cin >> V[i];
    }
    long long ans = 0;
    for(int l = 0; l <= min(k, n); l++){
        for(int r = 0; l + r <= min(k, n); r++){
            vector<long long> v;
            long long tmp = 0;
            for(int i = 0; i < l; i++){
                v.push_back(V[i]); 
                tmp += V[i];
            }
            for(int i = 0; i < r; i++){
                v.push_back(V[n-1-i]); 
                tmp += V[n-1-i];
            }
            sort(v.begin(), v.end());
            for(int i = 0; i < min((int)v.size(), k - l - r); i++){
                if(v[i] < 0) tmp -= v[i];
            }
            ans = max(tmp, ans);
        }
    }
    cout << ans << endl;
}