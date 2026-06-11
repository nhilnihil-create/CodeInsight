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
    int n,a,b; scanf("%d%d%d",&n,&a,&b);
    if(a+b-1>n||1LL*a*b<n){
        printf("-1\n"); return 0;
    }
    vector<int> ans;
    int cur=1;
    rep(rot,0,a){
        int len=min(b,(n-cur+1)-(a-rot-1));
        rrep(i,cur+len-1,cur-1)ans.push_back(i);
        cur+=len;
    }
    rep(i,0,n)printf("%d\n",ans[i]);
    return 0;
}