#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<pair<string,pair<int,int>>> p(n);
    rep(i,n){
        cin>>p[i].first>>p[i].second.first;
        p[i].second.first*=-1;
        p[i].second.second=i;
    }
    vector<int> v(n);
    sort(p.begin(),p.end());
    rep(i,n){
        int x=p[i].second.second;
        v[i]=x+1;
    }
    rep(i,n)cout<<v[i]<<endl;
}