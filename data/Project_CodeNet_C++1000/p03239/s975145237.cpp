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
    int n,T;cin>>n>>T;
    int ans=INT_MAX;
    for(int i=0,x,y;i<n;++i){
        cin>>x>>y;
        if(y<=T){
            ans=min(ans,x);
        }
    }
    if(ans==INT_MAX)cout<<"TLE";
    else cout<<ans;
}