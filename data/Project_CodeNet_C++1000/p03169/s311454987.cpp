#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define sz(x) (int)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 5e5+10;

double dp[310][310][310];

int main(){
fast;
int n;
cin>>n;
int cnt[4];
cnt[1]=cnt[2]=cnt[3]=0;

for(int i=0;i<n;i++) {
    int a;
    cin>>a;
    cnt[a]++;
}

dp[0][0][0]=0;
double N = cnt[1]+cnt[2]+cnt[3];
for(int total=1;total<=N;total++) {
    for(int i=total;i>=0;i--) {
        for(int j=total-i;j>=0;j--) {
            int k = total - (i+j);
            dp[i][j][k]=0;
            double num=0;
            double den = i+j+k;
            if(den==0)
            continue;

            if(i>0) num += i*dp[i-1][j][k];
            if(j>0) num += j*dp[i+1][j-1][k];
            if(k>0) num += k*dp[i][j+1][k-1];
            num+=N;
            dp[i][j][k]=num/den;
        }
    }
}

cout<<setprecision(12)<<dp[cnt[1]][cnt[2]][cnt[3]]<<endl;
return 0;
}