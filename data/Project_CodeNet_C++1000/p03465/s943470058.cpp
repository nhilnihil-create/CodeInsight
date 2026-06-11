#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,a[200005];
bitset<6000005>dp;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp |= (dp << a[i]);
    }
    vector<ll>v;
    for(int i=1; i<=4000002; i++){
        if(dp[i])v.pb(i);
    }
    
    cout << v[((int)v.size()-1) / 2];
    
    
    
    
    
    return 0;
}
