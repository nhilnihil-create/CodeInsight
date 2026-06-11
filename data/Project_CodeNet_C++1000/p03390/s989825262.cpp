#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(v) (int)v.size()
#define all(v) (v.begin(),v.end())
#define ll long long

const int N=105;
const int inf=2e9;


int main(){
    ios::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    int q;
    ll x,y,t,l,r,tmax;
    ll ans;
    cin>>q;
    while(q--){
        cin>>x>>y;
        t=sqrt(x*y);
        if(t*t==x*y) --t;
        ans=t*2-1;
        if(x==y){
            ++ans;
        }
        else{
            tmax=2*t+1;
            l=t;
            r=tmax-l;
            bool f1=0,f2=0;
            while(l<=r+2){
                if(!f1&&x<=l) {++l;f1=1;}
                if(!f2&&r<=y){--r;f2=1;}
                if(l*r>=x*y) {
                    --ans;
                    break;
                }
                ++l;
                --r;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
