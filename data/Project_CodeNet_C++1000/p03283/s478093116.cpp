#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 550
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000000;
const int MOD = 1000000007;
int dp[N][N];
int cnt[N][N];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    REP(i,m){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cnt[l][r]++;
    }
    REP(i,n){
        for(int j=i;j<n;j++){
            int tmp=0;
            for(int k=i;k<=j;k++){
            tmp+=cnt[k][j];
            }
            if(i==j){
                dp[i][j]=tmp;
            }else{
                dp[i][j]=tmp+dp[i][j-1];
            }

        }
    }
    vector<P>a(q);
    REP(i,q)cin>>a[i].first>>a[i].second;
    REP(i,q){
        OUT(dp[a[i].first-1][a[i].second-1]);
    }
    return 0;
}