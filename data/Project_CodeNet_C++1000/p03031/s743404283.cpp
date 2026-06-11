#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using vil=vector<int>;
using vii=vector<vil>;
using ll=long long;
main(){
    // cin
    int n,m;
    cin>>n>>m;
    vii l(n);
    rep(i,m){
        int k;
        cin>>k;
        rep(j,k){
            int s;
            cin>>s;
            s--;
            l.at(s).push_back(i);
        }
    }
    vil p(m);
    rep(i,m){
        cin>>p.at(i);
    }
    int ans=0;
    rep(bit,1<<n){
        vil t(m,0);
        rep(i,n){
            if(bit&(1<<i)){
                for(auto j:l.at(i)){
                    t.at(j)++;
                }
            }
        }
        bool flag=true;
        rep(i,m){
            if(t.at(i)%2!=p.at(i)){
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout<<ans<<endl;
}