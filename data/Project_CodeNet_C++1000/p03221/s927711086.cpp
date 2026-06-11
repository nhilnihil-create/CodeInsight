#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// 桁数を返す
int cnt_digits(ll X){
    int cnt=0;
    while(X>0){
        X/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>> v(m);

    rep(i,m){
        int p,y;
        cin>>p>>y;
        v[i]={{p,y},i};
    }

    sort(all(v));
    vector<string> ans(m,"");

    int num=1;
    int c=6-cnt_digits(v[0].first.first);
    rep(i,c) ans[v[0].second]+='0';
    ans[v[0].second]+=to_string(v[0].first.first);
    c=6-cnt_digits(num);
    rep(i,c) ans[v[0].second]+='0';
    ans[v[0].second]+=to_string(num);

    //cout<<ans[v[0].second]<<endl;
    
    for(int i=1;i<m;i++){
        if(v[i].first.first!=v[i-1].first.first) num=1;
        else num++;

        c=6-cnt_digits(v[i].first.first);
        rep(j,c) ans[v[i].second]+='0';
        ans[v[i].second]+=to_string(v[i].first.first);
        c=6-cnt_digits(num);
        rep(j,c) ans[v[i].second]+='0';
        ans[v[i].second]+=to_string(num);
    }

    rep(i,m) cout<<ans[i]<<endl;
}
