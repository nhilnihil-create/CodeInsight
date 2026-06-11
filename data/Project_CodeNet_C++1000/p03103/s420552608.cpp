#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<ll,int>> vec(n);
    rep(i,n) cin>>vec[i].first>>vec[i].second;//first=値段,second=上限
    sort(all(vec));
    ll buy=0,money=0;
    for(auto a:vec){
        money+=a.first*min(m,a.second);
        m=max(0,m-a.second);
        if(m==0) break;
    }
    cout<<money<<endl;
}