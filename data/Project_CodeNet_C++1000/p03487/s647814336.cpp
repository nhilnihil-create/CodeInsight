#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define umap unordered_map<ll, ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, ans = 0;
    cin >> n;
    
    umap x;
    for(ll i=0; i<n; i++){
        cin >> a;
        x[a]++;
    }
    a = 0;
    for(auto i:x){
        if(i.first > i.second){
            ans += i.second;
        }
        if(i.first < i.second){
            ans += (i.second - i.first);
        }
    }
    
    cout << ans << endl;
    return 0;
}