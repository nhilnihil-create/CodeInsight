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
const int MAX = 100005;
const int MOD = 1000000007;
ll dp[MAX];
int main(){
    int n,k;
    cin>>n>>k;
    vector<P>a(n);
    REP(i,n){
        int t,d;
        cin>>t>>d;
        t--;
        a[i]={d,t};
    }
    sort(ALL(a));
    reverse(ALL(a));
    vector<int>cnt(n+2,0);
    ll sum=0;
    int x=0;
    priority_queue<P,vector<P>,greater<P>>qmin;
    REP(i,k){
        sum+=a[i].first;
        if(cnt[a[i].second]==0)x++;
        cnt[a[i].second]++;
        qmin.push(a[i]);
    }
    priority_queue<P>qmax;
    vector<int>cnt2(n+2,0);
    for(int i=k;i<n;i++){
        if(cnt[a[i].second]==0&&cnt2[a[i].second]==0){
            cnt2[a[i].second]++;
            qmax.push(a[i]);
        }
    }
    dp[x]=sum;
    while(SZ(qmin)>0&&SZ(qmax)>0){
        P p=qmin.top();
        qmin.pop();
        if(cnt[p.second]>1){
            cnt[p.second]--;
            sum-=p.first;
            P r=qmax.top();
            qmax.pop();
            sum+=r.first;
            //cnt[r.second]++;
            x++;
            dp[x]=sum;
        }
    }
    ll ans=0;
    REP(i,x+3){
        if(dp[i]==0)continue;
        ans=max(ans,dp[i]+(ll)i*i);
    }
    OUT(ans);
    return 0;
}