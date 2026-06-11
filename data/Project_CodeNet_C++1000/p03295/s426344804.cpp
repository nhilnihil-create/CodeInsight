#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> data(m);
    rep(i,m){
        cin >> data[i].second >> data[i].first;
    }
    sort(data.begin(),data.end());
    int ans=0;
    int now=0;
    rep(i,m){
        if(now>data[i].second) continue;
        ans++;
        now=data[i].first;
    }
    cout << ans << endl;
}






/*

うーん。。。
int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<double,double>> island(n);
    rep(i,n) island[i].first=n+2, island[i].second=-4;
    rep(i,m){
        double a,b;
        cin >> a >> b;
        a--; b--;
        island[a].first=min(island[a].first,b);
        island[b].second=max(island[b].second,a);
    }
    rep(i,n){
        if(island[i].first==n+2) island[i].first=i;
        else island[i].first-=0.1;
        if(island[i].second==-4) island[i].second=i;
        else island[i].second+=0.1;
    }
    sort(island.begin(),island.end());
    
    rep(i,n){
        cout << "i " << i+1 << endl;
        cout << " " << island[i].first+1 << " " << island[i].second+1 << endl;
    }
    
    sort(island.begin(),island.end());
    double now=-1;
    double ans=0;
    rep(i,n){
        if(now>=island[i].second) continue;
        ans++;
        now=i;
        cout << "now   " << now+1 << endl;
    }
    cout << ans << endl;
}

*/