#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;


long double dp[305][305][305];
int cnt=302;
int main(){
    int n;
    cin>>n;
    cout.precision(17);
    int a[n+5];
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt1++;
        else if(a[i]==2) cnt2++;
        else cnt3++;
    }
    for(int k=0;k<=cnt;k++){
        for(int j=0;j+k<=cnt;j++){
            for(int i=0;k+i+j<=cnt;i++){
                if(i+j+k == 0 || i+j+k>n)continue;
                dp[i][j][k]= n;
                if(i)
                    dp[i][j][k]+=i*dp[i-1][j][k];
                if(j)
                    dp[i][j][k]+=j*dp[i+1][j-1][k];
                if(k)
                    dp[i][j][k]+=k*dp[i][j+1][k-1];

                dp[i][j][k] = dp[i][j][k]/(1.0*(i+j+k));
            }
        }
    }
    cout<<dp[cnt1][cnt2][cnt3];
    return 0;
}