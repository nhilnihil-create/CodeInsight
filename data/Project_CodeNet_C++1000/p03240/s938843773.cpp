#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<pair<P,ll>> point(N);
    rep(i,N){
        cin>>point.at(i).first.first>>point.at(i).first.second>>point.at(i).second;
    }
    rep(cx,101){
        rep(cy,101){
            bool j=true;
            ll H=0;
            rep(i,N){
                if(point.at(i).second==0)continue;
                P za=point.at(i).first;
                ll nowh=point.at(i).second+abs(cx-za.first)+abs(cy-za.second);
                if(H==0 && nowh>0)H=nowh;
                if(nowh!=H){j=false;break;}
            }
            rep(i,N){
                P za=point.at(i).first;
                ll nowh=H-abs(cx-za.first)-abs(cy-za.second);
                if(nowh<0)nowh=0;
                if(nowh!=point.at(i).second)j=false;
            }
            if(j){
                cout<<cx<<" "<<cy<<" "<<H<<endl;
                return 0;
            }
        }
    }
}