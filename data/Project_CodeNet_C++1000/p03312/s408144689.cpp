#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> cum(n);
    rep(i,n){
        if(i==0) cum[i]=a[i];
        else cum[i]=cum[i-1]+a[i];
    }
    ll res=1e17;
    for(ll M=1; M<n-2; M++){ //a[0]...a[M] / a[M+1]...a[n-1]
        ll p,q,r,s;
        ll left=0, right=M-1;
        while(right-left>1){
            //a[0]...a[mid] / a[mid+1]...a[M]
            //cum[mid] / cum[M]-cum[mid]
            //-mid ~ cum[M]-cum[mid]*2
            ll mid=(left+right)/2;
            if(cum[M]-2*cum[mid]>0) left=mid;
            else right=mid;
        }
        if(abs(cum[M]-2*cum[left]) < abs(cum[M]-2*cum[right])){
            p=cum[left]; q=cum[M]-cum[left];
        }else{
            p=cum[right]; q=cum[M]-cum[right];
        }
        
        left=M+1, right=n-2;
        while(right-left>1){
            //a[M+1]...a[mid] / a[mid+1]...a[n-1]
            //cum[mid]-cum[M+1] / cum[n-1]-cum[mid]
            //-mid ~ cum[n-1]-2*cum[mid]+cum[M+1]
            ll mid=(left+right)/2;
            if(cum[n-1]-2*cum[mid]+cum[M]>0) left=mid;
            else right=mid;
        }
        if(abs(cum[n-1]-2*cum[left]+cum[M]) < abs(cum[n-1]-2*cum[right]+cum[M])){
            r=cum[left]-cum[M]; s=cum[n-1]-cum[left];
        }else{
            r=cum[right]-cum[M]; s=cum[n-1]-cum[right];
        }

        vector<ll> V={p,q,r,s};
        sort(V.begin(), V.end());
        chmin(res, V[3]-V[0]);
    }
    cout<<res<<endl;
    return 0;
}