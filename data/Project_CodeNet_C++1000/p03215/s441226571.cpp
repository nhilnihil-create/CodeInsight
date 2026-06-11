#include <bits/stdc++.h>
using  namespace std;

long long n,k;
vector<long long > a,v;

long long solve();

int main(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0;i < n;++i)cin >> a[i];
    cout << solve() << endl;
    return 0;
}

long long  solve(){
    long long ans = 0;
    for(int i = 1;i < n;++i)a[i] += a[i-1];
    for(int i = 0;i< n;++i)
        for(int j = i;j < n;++j){
            long long now = a[j];
            if(i != 0)now -= a[i-1];
            v.push_back(now);
        }
    for(long long i = 40;i >= 0;--i){
        vector<long long> newv;
        int vsize = v.size();
        for(int j = 0;j < vsize;++j)
            if((v[j] >> i) & 1)newv.push_back(v[j]);
        if((int)newv.size() >= k)v = newv;
    }
    ans = v[0];
    for(int i = 0;i < k;++i)ans &= v[i];
    return ans;
}