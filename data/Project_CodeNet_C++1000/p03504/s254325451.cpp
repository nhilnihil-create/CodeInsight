#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,C;cin>>n>>C;
    vector<ll> end;
    vector<vector<P>> x(C);
    rep(i,n){
        ll s,t,c;cin>>s>>t>>c;
        x[c-1].push_back({s,t});
    }
    
    vector<P> st;
    rep(i,C){
        vector<P> xi = x[i];
        if(xi.size()==0)continue;
        sort(ALL(xi));
        ll s = xi[0].first,t=xi[0].second;
        rep2(j,1,xi.size()){
            P p = xi[j];
            if(t==p.first)t=p.second;
            else{
                st.push_back({2*s-1,2*t});
                s=xi[j].first,t=xi[j].second;
            }
        }
        st.push_back({2*s-1,2*t});
    }
    sort(ALL(st));

    rep(i,st.size()){
        P p = st[i];
        bool flag = false;
        rep(j,end.size()){
            if(end[j]<p.first){end[j]=p.second;flag=true;break;}
        }
        if(flag)continue;
        end.push_back(p.second);
    }
    cout<<end.size()<<endl;
    return 0;
}