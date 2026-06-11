#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<P> p;
    int l=s.length(),b,e,pre=s[0],cnt=0;
    p.push_back({pre-'0',1});
    rep(i,l-1){
        if(s[i+1]==pre) p[cnt].second++;
        else{
            p.push_back({s[i+1]-'0',1});
            cnt++;
            pre=s[i+1];
        }
    }
    b=s[0]-'0'; e=s[l-1]-'0';
    int ans=0;
    cnt++;
    rep(i,cnt){
        if(p[i].first==0){
            int x=min(2*k,cnt-i);
            int kari=0;
            for(int j=i; j<i+x; ++j){
                kari+=p[j].second;
            }
            ans=max(ans,kari);
        }
        else{
            int x=min(2*k+1,cnt-i);
            int kari=0;
            for(int j=i; j<i+x; ++j){
                kari+=p[j].second;
            }
            ans=max(ans,kari);
        }
        if(2*k-10>cnt-i) break;
    }
    cout<<ans<<endl;
    return 0;
}
