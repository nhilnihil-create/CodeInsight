#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        a[i]-=(i+1);
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]<0) ans-=a[i];
        else ans+=a[i];
    }
    ll mcnt=0;
    for(ll i=0;i<n;i++){
        if(a[i]>0){
            break;
        }
        mcnt++;
    }
    ll pcnt=n-mcnt;
    ll da=0;
    if(n%2==1){
        ll mid=n/2;
        if(mid>mcnt){
            while(a[mid]!=0){
                a[mcnt]-=da;
                ll b=a[mcnt];
                a[mcnt]=0;
                ans-=b*(pcnt-mcnt);
                da+=b;
                pcnt--;
                mcnt++;
            }
        }
        else {
            while(a[mid]!=0){
                a[n-pcnt-1]-=da;
                ll b=a[n-pcnt-1];
                a[n-pcnt-1]=0;
                ans-=b*(pcnt-mcnt);
                da+=b;
                pcnt++;
                mcnt--;
            }
        }
    }
    else {
        ll mid=n/2;
        if(mid>mcnt){
            while(mcnt!=pcnt){
                a[mcnt]-=da;
                ll b=a[mcnt];
                ans-=b*(pcnt-mcnt);
                da+=b;
                pcnt--;
                mcnt++;
            }
        }
        else {
            while(mcnt!=pcnt){
                a[n-pcnt-1]-=da;
                ll b=a[n-pcnt-1];
                ans-=b*(pcnt-mcnt);
                da+=b;
                pcnt++;
                mcnt--;
            }
        }
    }
    cout << ans << endl;
}