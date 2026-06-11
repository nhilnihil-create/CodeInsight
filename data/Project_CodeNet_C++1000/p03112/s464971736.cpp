#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> s(A+2),t(B+2);
    s[0]=-1e+11;
    t[0]=-1e+11;
    s[A+1]=1e+11;
    t[B+1]=1e+11;
    
    rep2(i,1,A+1) cin >> s[i];
    rep2(i,1,B+1) cin >> t[i];

    vector<ll> X(Q);
    rep(i,Q) cin >> X[i];
    ll s1,s2,t1,t2;
    rep(i,Q){
        ll ans=INF;
        ll ans_s=INF;
        ll ans_t=INF;
        ll x=X[i];

        // s1通る時
        auto itr = lower_bound(s.begin(),s.end(),x);
        s1=*itr;
        s2=*(itr-1);
        if(abs(s1-x)>abs(s2-x)){
            swap(s1,s2);
            ans_s=abs(s1-x);
            auto itr = lower_bound(t.begin(),t.end(),s1);
            t1=*itr;
            t2=*(itr-1);
            if(t1>x) ans_s+=min(abs(s1-t1),abs(s1-t2));
        }else{
            ans_s=abs(s1-x);
            auto itr = lower_bound(t.begin(),t.end(),s1);
            t1=*itr;
            t2=*(itr-1);
            if(t2<x) ans_s+=min(abs(s1-t1),abs(s1-t2));
        }

        // t1通る時
        itr = lower_bound(t.begin(),t.end(),x);
        t1=*itr;
        t2=*(itr-1);
        if(abs(t1-x)>abs(t2-x)){
            swap(t1,t2);
            ans_t=abs(t1-x);
            auto itr = lower_bound(s.begin(),s.end(),t1);
            s1=*itr;
            s2=*(itr-1);
            if(s1>x) ans_t+=min(abs(t1-s1),abs(t1-s2));
        }else{
            ans_t=abs(t1-x);
            auto itr = lower_bound(s.begin(),s.end(),t1);
            s1=*itr;
            s2=*(itr-1);
            if(s2<x) ans_t+=min(abs(t1-s1),abs(t1-s2));
        }
        ans=min(ans_s,ans_t);
        cout << ans << endl;
    }
}
