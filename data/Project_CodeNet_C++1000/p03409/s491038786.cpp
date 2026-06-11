#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i))
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(x,v) for(const auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義 #define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//lambda: [&](int x, int y){return x<y;}

signed main(void){
    int n;cin>>n;
    vector<pint> red(n),blue(n);
    rep(i,n)cin>>red[i].first>>red[i].second;
    rep(i,n)cin>>blue[i].first>>blue[i].second;

    vsort(blue);
    vfsort(red,[](pint x,pint y){return x.second>y.second;});

    int ans=0;
    vint used(n,0);
    rep(i,n){
        rep(j,n){
            if(used[j]>0)continue;
            if(red[j].first<blue[i].first&&red[j].second<blue[i].second){
                used[j]++;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}
