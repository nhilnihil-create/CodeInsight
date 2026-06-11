#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<pair<ll,pair<int,int>>> p(n);
    rep(i,n){
        ll h,x,y;cin>>x>>y>>h;
        p[i]={h,{x,y}};
    }
    sort(p.rbegin(),p.rend());
    rep(cx,101)rep(cy,101){
        ll H=-1;
        bool jud=true;
        rep(i,n){
            ll h=p[i].first,x=p[i].second.first,y=p[i].second.second;
            if(H==-1) H=h+abs(x-cx)+abs(y-cy);
            else{
                ll nh=H-abs(x-cx)-abs(y-cy);
                chmax(nh,(ll)0);
                if(h!=nh){
                    jud=false;
                    break;
                }
            }
        }
        if(jud){
            cout<<cx<<" "<<cy<<" "<<H<<endl;
            return 0;
        }
    }
}