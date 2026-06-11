#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    ll s; cin>>s;
    int ans = 1;
    
    map<ll,int> mp;
    
    while(!mp.count(s)){
        mp[s]++;
        ans++;
        if(s%2) s = 3*s + 1;
        else s /= 2;
    }
    
    cout << ans <<endl;
    return 0;
}