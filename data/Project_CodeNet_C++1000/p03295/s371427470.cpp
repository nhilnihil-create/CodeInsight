#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    vector<P>a(m);
    REP(i,m){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        a[i]={x,y};
    }
    sort(ALL(a));
    int l=0;
    int r=n-1;
    int ans=0;
    REP(i,m){
        if(l<=a[i].first&&a[i].first<r){
            l=max(l,a[i].first);
            r=min(r,a[i].second);
        }else{
            ans++;
            l=a[i].first;
            r=a[i].second;
        }
        //cout<<l<<" "<<r<<endl;
    }
    ans++;
    OUT(ans);
    return 0;
}