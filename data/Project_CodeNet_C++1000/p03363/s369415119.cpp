#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    vector<long long> s(n+1);
    s[0] = 0;
    for(int i=0;i<n;++i){
        s[i+1] = s[i] + a[i];
    }
    map<long long,long long> mp;
    for(int i=0;i<=n;++i) mp[s[i]]++;
    long long ans=0;
    for(auto itr : mp){
        ans += itr.second*(itr.second-1)/2;
    }
    //ans += mp[0];
    cout << ans << endl;
    return 0;
}