#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n,m;cin>>n>>m;
    vector<int> x(m);rep(i,m)cin>>x[i];
    sort(x.begin(),x.end());
    vector<int> d(m);
    for(int i =0;i<m-1;++i){
        d[i] = abs(x[i+1]-x[i]);
    }
    ll sum = 0;
    sort(d.begin(),d.end(),greater<int>());
    for(int i =n-1;i<m;++i){
        sum+=d[i];
    }
    cout<<sum<<endl;
}