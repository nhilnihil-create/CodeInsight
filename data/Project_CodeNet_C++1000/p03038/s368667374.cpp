#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    vector<pair<int,int>> d(m);
    rep(i,0,m){
        int b,c;cin>>b>>c;
        d[i] = make_pair(c,b);
    }
    sort(d.begin(),d.end());
    int y = 0;
    for(int i=m-1;i>=0;i--){
        int r = d[i].first;
        int l = d[i].second;
        while(y<n&&l>0){
            if (r>a[y]){
                a[y] = r;
                l--;
            }
            y++;
        }
    }
    ll sum = 0;
    rep(i,0,n){
        sum+=a[i];
    }
    cout<<sum<<endl;
}