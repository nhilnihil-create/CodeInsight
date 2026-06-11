#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//template end



int main(){
    string s; cin>>s; int n=s.size();
    bool f=0;
    rep(i,0,n-1)if(s[i]!=s[n-i-2])f=1;
    if(s[0]=='0'||s[n-1]=='1')f=1;
    if(f){
        printf("-1\n"); return 0;
    }
    vector<pair<int,int>> ans; int cur=0;
    rep(i,0,n-1){
        ans.push_back({cur,i+1});
        if(s[i]=='1')cur=i+1;
    }
    rep(i,0,n-1)printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    return 0;
}