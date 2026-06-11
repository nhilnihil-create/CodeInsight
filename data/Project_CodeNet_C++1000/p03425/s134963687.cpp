#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    ll t;
    cin >> t;
    vector<ll> d(5, 0);
    while(t--){
        string s;
        cin>>s;
        if(s[0]=='M')
            d[0]++;
        if(s[0]=='A')
            d[1]++;
        if(s[0]=='R')
            d[2]++;
        if(s[0]=='C')
            d[3]++;
        if(s[0]=='H')
            d[4]++;
    }
    
    ll ans=0; 
 
    for(int i=0; i<5; ++i){
        for(int j=i+1; j<5; ++j){
            for(int k=j+1; k<5; ++k)
                ans += d[i]*d[j]*d[k];
        }
    }
    cout << ans;
}
