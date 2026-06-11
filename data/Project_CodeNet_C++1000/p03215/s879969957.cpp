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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    vector<ll>sum(n+1);
    REP(i,n)sum[i+1]=sum[i]+a[i];
    vector<ll>x(n*(n+1)/2);
    int p=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            x[p++]=(ll)sum[i]-sum[j];
        }
    }
    ll t=1LL<<40;
    ll ans=0;
    while(t>0){
        int cnt=0;
        vector<ll>tmp;
        for(int i=0;i<max(p,k);i++){
            if((ll)x[i]&t){
                cnt++;
                tmp.push_back(x[i]);
            }
        }
        if(cnt>=k){
            ans+=t;
            if(cnt<p){
                REP(i,cnt)x[i]=tmp[i];
                p=cnt;
            }
        }
        if(t==1)break;
        t=t>>1;
    }
    OUT(ans);
    return 0;
}