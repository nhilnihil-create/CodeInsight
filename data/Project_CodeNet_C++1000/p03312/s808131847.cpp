#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    ll a[n];
    ll sum[n+1]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }
    ll ans = 1e18;
    for(int m=2;m<n-1;m++){
        int l=1,rr=m;
        while(rr-l>1){
            int mid = (l+rr)/2;
            if(sum[mid]>sum[m]/2){
                rr=mid;
            }
            else l=mid;
        }

        int d=m+1,u=n;
        while(u-d>1){
            int mid = (u+d)/2;
            if(sum[mid]-sum[m]>(sum[n]-sum[m])/2){
                u=mid;
            }
            else d=mid;
        }
        ll p=sum[l],q=sum[m]-sum[l];
        ll r=sum[d]-sum[m],s=sum[n]-sum[d];
        ll dif = max(max(p,q),max(r,s)) - min(min(p,q),min(r,s));
        ans = min(ans,dif);
        if(l!=m-1){
            l++;
            p=sum[l],q=sum[m]-sum[l];
            r=sum[d]-sum[m],s=sum[n]-sum[d];
            dif = max(max(p,q),max(r,s)) - min(min(p,q),min(r,s));
            ans = min(ans,dif);
            l--;
        }
        if(d!=n-1){
            d++;
            p=sum[l],q=sum[m]-sum[l];
            r=sum[d]-sum[m],s=sum[n]-sum[d];
            dif = max(max(p,q),max(r,s)) - min(min(p,q),min(r,s));
            ans = min(ans,dif);
            d--;
        }
        if(l!=m-1 && d!=n-1){
            d++,l++;
            p=sum[l],q=sum[m]-sum[l];
            r=sum[d]-sum[m],s=sum[n]-sum[d];
            dif = max(max(p,q),max(r,s)) - min(min(p,q),min(r,s));
            ans = min(ans,dif);
            
        }

        //cerr<<l<<" "<<m<<" "<<d<<" "<<dif<<endl;
    }
    cout << ans << endl;
    

 
    
}