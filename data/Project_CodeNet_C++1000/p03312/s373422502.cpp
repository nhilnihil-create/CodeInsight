#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
#define pb push_back
typedef long long ll;
const ll INF = 1LL << 60;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n),s(n+1);
    s[0] = 0;
    rep(i,n){
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    ll ans = INF;
    reps(i,2,n-1){
        ll tmp_ans;
        ll ng = 0;
        ll ok = i-1;
        while(abs(ng-ok)>1){
            int mid = (ng+ok)/2;
            if(s[mid] > s[i]-s[mid]){ok = mid;}
            else{ng = mid;}
        }
        ll p1 = s[ng];
        ll p2 = s[ok];
        ll q1 = s[i]-s[ng];
        ll q2 = s[i]-s[ok];
        ll p,q;
        if(abs(p1-q1)<abs(p2-q2)){p=p1;q=q1;}
        else{p=p2;q=q2;}

        ng = i+1;
        ok = n-1;
        while(abs(ng-ok)>1){
            int mid = (ng+ok)/2;
            if(s[mid]-s[i] > s[n]-s[mid]){ok = mid;}
            else{ng = mid;}
        }
        ll r1 = s[ng]-s[i];
        ll r2 = s[ok]-s[i];
        ll s1 = s[n]-s[ng];
        ll s2 = s[n]-s[ok];
        ll r,s;
        if(abs(r1-s1)<abs(r2-s2)){r=r1;s=s1;}
        else{r=r2;s=s2;}

        tmp_ans = max(max(p,q),max(r,s)) - min(min(p,q),min(r,s));
        ans = min(ans,tmp_ans);
    }
    cout << ans;
}