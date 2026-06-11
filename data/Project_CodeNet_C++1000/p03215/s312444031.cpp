#include <bits/stdc++.h>
#define N 100005
#define INF 0x3f3f3f3f 
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans, res; 

void print(bitset<64> bs){
    ll res = 0;
    for(int i=0; i<64; i++) if(bs[i] == 1) res+=pow(2,i);
    cout << res << endl;
}

int main(){
    int n, k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    vector <ll> v;
    for(int i=0; i<n; i++){
        ll cntr = arr[i];
        v.push_back(cntr);
        for(int j=i+1; j<n; j++){
            cntr+=arr[j];
            v.push_back(cntr);
        }
    }
    for(int i=40; i>=0; i--){
        ans+=(1ll<<i);
        int cntr = 0;
        for(int j=0; j<v.size(); j++) if((v[j]&ans) == ans) cntr++;
        if(cntr < k) ans-=(1ll<<i);
    }
    cout << ans;
    return 0;
}
