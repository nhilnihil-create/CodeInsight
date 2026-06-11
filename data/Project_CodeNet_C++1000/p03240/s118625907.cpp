#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<tuple<int,int,int64_t>> V;
    rep(i,0,N){
        int x,y;
        int64_t h;
        cin>>x>>y>>h;

        V.emplace_back(h,x,y);
    }

    sort(ToEnd(V),greater<tuple<int,int,int64_t>>());

    tuple<int,int,int64_t> ans;
    rep(cx,0,101){
        bool match;
        rep(cy,0,101){
            match=true;
            int64_t ch=get<0>(V.front())+abs(get<1>(V.front())-cx)+abs(get<2>(V.front())-cy);
            rep(i,0,N){
                int x,y;
                int64_t h;
                tie(h,x,y)=V.at(i);
                
                int64_t _h=max((int64_t)0,ch-abs(x-cx)-abs(y-cy));
                if(h!=_h){
                    match=false;
                    break;
                }
            }
            if(match) ans=make_tuple(cx,cy,ch);
        }
        if(match) break;
    }

    cout<<get<0>(ans)<<" "<<get<1>(ans)<<" "<<get<2>(ans)<<endl;
}