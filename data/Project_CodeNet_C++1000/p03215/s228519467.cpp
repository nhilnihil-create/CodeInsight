#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n, k;
    cin >> n >> k;
    vector<i64> a;
    for(int i=0;i<n;++i){
        i64 tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<i64> cumsum(n+1);
    for(int i=1;i<=n;++i){
        cumsum[i] = cumsum[i-1] + a[i-1];
    }
    vector<i64> v;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            v.push_back(cumsum[j+1]-cumsum[i]);
        }
    }
    i64 ans = 0;
    for(i64 i=63;i>=0;--i){
        vector<i64> v2;
        for(auto e: v){
            if(e&(1ll<<i))v2.push_back(e);
        }
        if(v2.size() >= k){
            ans |= (1ll<<i);
            v = v2;
        }
    }

    cout << ans << endl;

    return 0;
}