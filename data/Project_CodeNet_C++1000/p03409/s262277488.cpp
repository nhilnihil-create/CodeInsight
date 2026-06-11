#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<pair<int,int>> p1(n),p2(n);
    rep(i,n) cin>>p1[i].first>>p1[i].second;
    rep(i,n) cin>>p2[i].first>>p2[i].second;
    sort(p2.begin(),p2.end());
    vector<int> xb(n),yb(n);
    vector<bool> used(n,false);
    int res=0;
    rep(i,n){
        int now=-1,it=-1;
        rep(j,n){
            if(!used[j]&&p2[i].first-p1[j].first>0&&p2[i].second-p1[j].second>0){
                if(chmax(now,p1[j].second))it=j;
            }
        }
        if(it==-1)continue;
        used[it]=true;
        res++;
    }
    //rep(i,n) cout<<used[i]<<endl;
    cout<<res<<endl;
}