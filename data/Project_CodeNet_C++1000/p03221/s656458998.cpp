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
const int Maxn=1e5+10;
set<pair<int,int>>st[Maxn];
map<int,string>mp;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1,x,y;i<=m;++i){
        cin>>x>>y;
        st[x].insert({y,i});
    }
    for(int i=1;i<=n;++i){
        int cnt=1;
        string s1=to_string(i);
        while(int(s1.size())<6)s1="0"+s1;
        for(auto x:st[i]){
            string s2=to_string(cnt);
            while(int(s2.size())<6)s2="0"+s2;
            mp[x.second]=s1+s2;
            ++cnt;
        }
    }
    for(auto x:mp)cout<<x.second<<"\n";
}