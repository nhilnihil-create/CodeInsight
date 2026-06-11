#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=305,M=1e9+7;
//did u check when n=1?
//is mxN correct?
double dp[305][305][305],ans[mxN][mxN][mxN];
vi v(4);
int n;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[x]++;
    }
    dp[v[1]][v[2]][v[3]]=1;
    for(int c=n;c>=0;c--){
        for(int b=n;b>=0;b--){
            for(int a=n;a>=0;a--){
                if(a==0 && b==0 && c==0)continue;
                if(a+b+c>n)continue;
                double waste=(double)(n-(a+b+c))/(double)n;
                double twaste=waste/(1-waste) +1;
                ans[a][b][c]+=twaste*dp[a][b][c];
                if(a!=0){
                    dp[a-1][b][c]+=dp[a][b][c]*(double)(a)/(double)(a+b+c);
                    ans[a-1][b][c]+=ans[a][b][c]*(double)(a)/(double)(a+b+c);
                }
                if(b!=0){
                    dp[a+1][b-1][c]+=dp[a][b][c]*(double)(b)/(double)(a+b+c);
                    ans[a+1][b-1][c]+=ans[a][b][c]*(double)(b)/(double)(a+b+c);
                }
                if(c!=0){
                    dp[a][b+1][c-1]+=dp[a][b][c]*(double)(c)/(double)(a+b+c);
                    ans[a][b+1][c-1]+=ans[a][b][c]*(double)(c)/(double)(a+b+c);
                }
            }
        }
    }   
    /*    for(int c=n;c>=0;c--){
        for(int b=n;b>=0;b--){
            for(int a=n;a>=0;a--){
               cout<<a<<" "<<b<<" "<<c<<" "<<dp[a][b][c]<<"\n";
            }
        }
    }*/
    cout<<fixed<<setprecision(10)<<ans[0][0][0];
}