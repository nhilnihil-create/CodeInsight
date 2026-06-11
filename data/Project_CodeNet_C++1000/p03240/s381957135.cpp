#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<tuple<int,int,int>>vt;
    for(int i=0,x,y,z;i<n;++i){
        cin>>x>>y>>z;
        vt.emplace_back(make_tuple(x,y,z));
    }
    for(int i=0;i<=100;++i){
        for(int j=0;j<=100;++j){
            int h=-1;
            for(auto x:vt){
                int val=abs(get<0>(x)-i)+abs(get<1>(x)-j);
                if(get<2>(x)>0){
                    if(h==-1)
                    h=get<2>(x)+val;
                    else if(h!=get<2>(x)+val)
                        goto label;
                }
            }
            for(auto x:vt){
                int val=abs(get<0>(x)-i)+abs(get<1>(x)-j);
                if(get<2>(x)==0){
                    if(h>val)goto label;
                }
            }
            cout<<i<<" "<<j<<" "<<h;return 0;
            label:;
        }
    }
}