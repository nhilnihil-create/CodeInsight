#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
bool cf(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)return a.second<b.second;
    else return a.first<b.first;
}
signed main(){
    int n;cin>>n;
    int res=0;bool ok=true;
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int>> s(n);
    rep(i,n){
        cin>>a[i];
        b[i].first=a[i];
        b[i].second=i;
        s[i].first=i-a[i];
        s[i].second=i;
    }
    sort(b.begin(),b.end(),cf);
    sort(s.begin(),s.end(),cf);
    reverse(s.begin(),s.end());
    res+=s[0].second-s[0].first;
    rep1(i,n-1){
        if(s[i].first<0)ok=false;
        if(s[i-1].first!=s[i].first){
            res+=s[i].second-s[i].first;
        }
        //cout<<s[i].first<<" "<<s[i].second<<endl;
    }
    if(a[0]!=0)ok=false;
    rep1(i,n-1){
        if(a[i]<=a[i-1]||a[i]==a[i-1]+1)continue;
        ok=false;
    }
    if(ok)cout<<res;
    else cout<<"-1";
    cout<<endl;
    return 0;
}