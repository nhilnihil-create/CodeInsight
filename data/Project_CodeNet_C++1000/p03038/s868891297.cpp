#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<pair<int,int>> v(m);
    rep(i,m){
        int b,c;
        cin>>b>>c;
        v[i]={c,b};
    }

    sort(all(a));
    sort(all(v));
    reverse(all(v));
    vector<int> com(n,0);
    vector<pair<int,int>> v2;
    int cnt=0;
    rep(i,m){
        if(cnt+v[i].second>n){
            int x=n-cnt;
            v2.push_back({v[i].first,x});
        }
        else{
            cnt+=v[i].second;
            v2.push_back(v[i]);
        }
    }
    int id=0;
    rep(i,v2.size()){
        int add=v[i].second;
        for(int j=id;j<min(id+add,n);j++){
            com[j]=v[i].first;
        }
        id+=add;
        if(id>=n) break;
    }

    //rep(i,n) cout<<com[i]<<" ";
    //cout<<endl;

    ll ans=0;
    rep(i,n){
        ans+=max(a[i],com[i]);
    }

    cout<<ans<<endl;
}