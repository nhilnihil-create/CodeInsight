#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m;
    cin>>n>>m;
    vector<P> p(m);
    rep(i,m) cin>>p[i].first>>p[i].second;
    vector<vector<int>> nu(n+1);
    rep(i,m){
        nu[p[i].first].push_back(p[i].second);
    }
    rep(i,n+1){
        nu[i].push_back(0);
        sort(btoe(nu[i]));
    }
    rep(i,m){
        int f=p[i].first, s=p[i].second;
        int sta=0, goa=nu[f].size()-1;
        int mid=(sta+goa)/2;
        while(goa-sta>1){
            if(nu[f][mid]<s) sta=mid;
            else goa=mid;
            mid=(sta+goa)/2;
        }
        int x=goa;
        cout<<f/100000<<(f/10000)%10<<(f/1000)%10<<(f/100)%10<<(f/10)%10<<f%10<<x/100000<<(x/10000)%10<<(x/1000)%10<<(x/100)%10<<(x/10)%10<<x%10<<endl;
    }
    return 0;
}