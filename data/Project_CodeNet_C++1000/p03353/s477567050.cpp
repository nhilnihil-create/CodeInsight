#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s;
    int k, n;
    cin>>s>>k;
    n=s.size();
    map<string,int> mp;
    for(int i=n; i>0; --i){
        if(n-i>=6) break;
        rep(j,i){
            mp[s.substr(j,(n-i+1))]++;
        }
    }
    int cnt=0;
    string ans;
    for(auto &v: mp){
        ans=v.first;
        cnt++;
        if(cnt==k) break;
    }
    cout<<ans<<endl;
    return 0;
}