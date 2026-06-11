
#include <bits/stdc++.h>

#define ll int64_t
using namespace std;
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){
    ll n,m;
  IOS
    cin>>n>>m;
    ll a[n];
    
    fo(i,n) cin>>a[i];
    map<ll,ll> mp;
    ll tmp=0;
    fo(i,n){
        tmp=(tmp+a[i])%m;
        mp[tmp]++;

    }
    ll ans=0;
    for(auto kk:mp){
        if(kk.second>1){
            ll tmp= kk.second*(kk.second-1);

            tmp=tmp/2;
            ans+=tmp;
        }
    }
    ans+=mp[0];
    cout<<ans<<endl;

}