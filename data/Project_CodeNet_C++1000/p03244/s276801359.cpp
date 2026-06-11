#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>odd;
    vector<ll>even;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(i%2==0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    ll ecnt=1,ocnt=1;
    ll er=1,cr=1;
    ll ex=0,ox=0;
    for(ll i=1;i<even.size();i++){
        if(even[i-1]==even[i]){
            er++;
            if(er>ecnt) ex=i;
            ecnt=max(er,ecnt);
            continue;
        }
        er=1;
    }
    for(ll i=0;i<odd.size();i++){
        if(odd[i-1]==odd[i]){
            cr++;
            if(cr>ocnt) ox=i;
            ocnt=max(cr,ocnt);
            continue;
        }
        cr=1;
    }
    if(odd[ox]==even[ex]){
        cr=1,er=1;
        ll ocnt2=0,ecnt2=0;
        for(ll i=1;i<even.size();i++){
            if(even[i-1]==even[i]&&even[i]!=even[ex]){
                er++;
                ecnt2=max(er,ecnt2);
                continue;
            }
            if(even[i-1]==even[i]&&even[ex]==even[i]) continue;
            ecnt2=max(ecnt2,er);
            er=1;
        }
        for(ll i=1;i<odd.size();i++){
            if(odd[i-1]==odd[i]&&odd[i]!=odd[ox]){
                cr++;
                ocnt2=max(cr,ocnt2);
                continue;
            }
            if(odd[i-1]==odd[i]&&odd[i]==odd[ox]) continue;
            ocnt2=max(ocnt2,cr);
            cr=1;
        }
        if(ocnt+ecnt2>ocnt2+ecnt) ecnt=ecnt2;
        else ocnt=ocnt2;
    }
    ll ans=n-ecnt-ocnt;
    cout << ans << endl;
}