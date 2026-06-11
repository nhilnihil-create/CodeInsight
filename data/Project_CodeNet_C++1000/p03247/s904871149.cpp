#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll x[1001],y[1001];
int n;
int main(){
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i];
    int c;
    c=abs(x[0]+y[0])%2;
    FOR(i,1,n){
        if(abs(x[i]+y[i])%2!=c){
            c=-1;
            break;
        }
    }
    if(c==-1){
        cout<<-1<<endl;
        return 0;
    }
    if(c==1){
        cout<<31<<endl;
        rep(i,31) cout<<(1<<(30-i))<<" ";
        cout<<endl;
    }
    else{
        cout<<32<<endl;
        cout<<1<<" ";
        rep(i,31) cout<<(1<<(30-i))<<" ";
        //cout<<1<<endl;
    }
    rep(i,n){
        ll tu=x[i]+y[i],tv=x[i]-y[i];
        string ans;
        if(c==0) ans+="R",--tu,--tv;
        for(int i=30;i>=0;--i){
            ll tmp=1<<i;
            if(tu>=0&&tv>=0){
                ans+="R";
                tu-=tmp,tv-=tmp;
            }
            else if(tu<0&&tv<0){
                ans+="L";
                tu+=tmp,tv+=tmp;
            }
            else if(tu>=0&&tv<0){
                ans+="U";
                tu-=tmp,tv+=tmp;
            }
            else if(tu<0&&tv>=0){
                ans+="D";
                tu+=tmp,tv-=tmp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}