#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }

    int ans = 0;
    for(auto p:mp){
        if(p.first == p.second) continue;
        if(p.second-p.first < 0) ans += p.second;
        else ans += p.second-p.first;
    }

    cout << ans << endl;

    return 0;
}