#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int one=0,two=0,three=0;
    for(int i=0 ; i<n ; i++){
        int x;
        cin>>x;
        if(x==1)
        one++;
        else if(x==2)
        two++;
        else
        three++;
    }
    double dp[n+1][n+1][n+1];
    memset(dp,0,sizeof(dp));
    
    // dp[0][0][0]=1;
    for(int i=0 ; i<=three ; i++){
        for(int j=0 ; j<=three+two ; j++){
            for(int k=0 ; k<=n ; k++){
                if(i+j+k<=n && (i!=0 || j!=0 || k!=0)){
                    double p1=k/(double)n;
                    double p2=j/(double)n;
                    double p3=i/(double)n;
                    double p0=1-p1-p2-p3;
                    // cout<<k<<" "<<j<<" "<<i<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
                    dp[k][j][i]+=(k-1>=0?n+k*dp[k-1][j][i]:n);
                    dp[k][j][i]+=(j-1>=0?j*dp[k+1][j-1][i]:0);
                    dp[k][j][i]+=(i-1>=0?i*dp[k][j+1][i-1]:0);
                    dp[k][j][i]/=(i+j+k);
                    // dp[k][j][i]=(1+p1*dp[k+1][j][i] + p2*dp[k-1][j+1][i] + p3*dp[k][j-1][i+1])/(1-p0);
                }
            }
        }
    }
    // cout<<dp[one][two][three]<<" "<<dp[one][two+1][three-1]<<" "<<dp[one+1][two][three-1];//<<" "<<dp[one-3][two][three]<<endl;
    printf("%.10lf",dp[one][two][three]);
    return 0;
}
