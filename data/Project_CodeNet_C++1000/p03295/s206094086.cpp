#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m; cin>>n>>m;
    map<int,int> mp;
    rep(i,m){
        int a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        if(mp[a]==0) mp[a]=b;
        else mp[a]=min(mp[a],b);
    }
    int ans=0, a=0;
    while(a!=n){
        if(mp[a]==0) a++;
        else{
            ans++;
            int b=mp[a]-1;
            vector<int> p;
            for(int i=a; i<=b; ++i){
                if(mp[i]!=0) p.push_back(mp[i]);
            }
            sort(btoe(p));
            a=p[0];
        }
    }
    cout<<ans<<endl;
    return 0;
}