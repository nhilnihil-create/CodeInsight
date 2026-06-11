#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b,q;cin>>a>>b>>q;
    ll s[a+1];for(ll i=0;i<a;i++)cin>>s[i];
    s[a]=1e15;
    ll ns[a+1];for(ll i=0;i<a;i++)ns[i]=-1*s[i];
    sort(ns,ns+a);
    ns[a]=1e15;
    ll t[b+1];for(ll i=0;i<b;i++)cin>>t[i];
    t[b]=1e15;
    ll nt[b+1];for(ll i=0;i<b;i++)nt[i]=-1*t[i];
    sort(nt,nt+b);
    nt[b]=1e15;
    while(q--){
        ll x;cin>>x;

        ll rs = lower_bound(s,s+a+1,x) - s;
        ll ls = lower_bound(ns,ns+a+1,-1*x) - ns;

        rs = s[rs];
        ls = ns[ls]*(-1);

        ll rt = lower_bound(t,t+b+1,x) - t;
        ll lt = lower_bound(nt,nt+b+1,-1*x) - nt;

        rt=t[rt];
        lt=nt[lt]*(-1);


        ll op1 = max(rs-x,rt-x);
        ll op2 = max(x-ls,x-lt);
        ll op3 = rt - ls + min(x-ls , rt-x);
        ll op4 = rs - lt + min(rs-x , x-lt);

        //cout<<ls<<" "<<lt<<" "<<x<<" "<<rs<<" "<<rt<<" "<<op1<<" "<<op2<<" "<<op3<<" "<<op4<<"\n";
        cout<<min({op1,op2,op3,op4})<<"\n";
    }
}