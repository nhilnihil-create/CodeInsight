#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll INF=1e18+1;

int main(void){
    int a, b, q;
    cin>>a>>b>>q;
    vector<ll> s(a+2);
    vector<ll> t(b+2);
    vector<ll> x(q);
    rep(i, a) cin>>s[i+1]; 
    rep(i, b) cin>>t[i+1];
    rep(i, q) cin>>x[i];
    s[0]=-INF;
    s[a+1]=INF;
    t[0]=-INF;
    t[b+1]=INF;
    rep(i, q){
        ll start=x[i];
        ll s1, s2, t1, t2;
        /*二分探索してstartの西と東を求める*/

        int lefts=0;
        int rights=a+1;
        while(rights-lefts>1){
            if(s[(lefts+rights)/2]>start) rights=(lefts+rights)/2;
            else lefts=(lefts+rights)/2;
        }
        int s1_idx=lefts;
        int s2_idx=rights;

        int leftt=0;
        int rightt=b+1;
        while(rightt-leftt>1){
            if(t[(leftt+rightt)/2]>start) rightt=(leftt+rightt)/2;
            else leftt=(leftt+rightt)/2;
        }
        int t1_idx=leftt;
        int t2_idx=rightt;
        vector<ll> kouho(4);
        s1=s[s1_idx];
        s2=s[s2_idx];
        t1=t[t1_idx];
        t2=t[t2_idx];
        //cout<<s1<<", "<<s2<<", "<<t1<<", "<<t2<<endl;
        kouho[0]=max(start-t1, start-s1);
        kouho[1]=min(-2*s1+t2+start, 2*t2-s1-start);
        kouho[2]=max(s2-start, t2-start);
        kouho[3]=min(2*s2-t1-start, s2-2*t1+start);
        ll ans=INF;
        rep(j, 4){
            //cout<<"kouho : "<<kouho[j]<<endl;
            ans=min(kouho[j], ans);
        }

        cout<<ans<<endl;
    }

    return 0;

}