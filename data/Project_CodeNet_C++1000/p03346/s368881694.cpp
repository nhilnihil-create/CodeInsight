#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        ll n;
        cin>>n;
        ll a[n];
        ll index[n];
        for(ll i=0;i<n;i++){
                cin>>a[i];
                a[i]--;
                index[a[i]]=i;
        }
        sort(a,a+n);
        ll mx_unchanged=0,present_unchanged=0,previous_index=-1;
        for(ll i=0;i<n;i++){
                if(index[a[i]] > previous_index) present_unchanged++;
                else present_unchanged=1;
                mx_unchanged=max(mx_unchanged , present_unchanged);
                previous_index = index[a[i]];
        }
        cout<<n-mx_unchanged<<"\n";
}
