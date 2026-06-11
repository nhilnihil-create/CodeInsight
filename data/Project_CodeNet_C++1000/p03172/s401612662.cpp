// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "M - Candies"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 1e5;
const int mod = 1e9 + 7;

int dp[101][maxn+1];
int tmp[maxn+1];
int a[101];

void add(int &x, int val){
    x+=val;
    if (x>mod) x-=mod;
    if (x<0) x+=mod;
}

int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int n,k;
    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][k]=1;
    for(int i=1;i<=n;i++){

        for(int j=0;j<=k;j++){
            add(tmp[ max(0,j-a[i]) ], dp[i-1][j] );
            if (j+1<=k) add(tmp[j+1],-dp[i-1][j]);
            /*
            tmp[ max(0,j-a[i] ) ] += dp[i-1][j];
            if (j+1<=k) tmp[j+1] -= dp[i-1][j];
            */
        }
        //for(int j=0;j<=k;j++) cout<<tmp[j]<<" ";
        //cout<<endl;
        int presum=0;
        for(int j=0;j<=k;j++){
            add(presum,tmp[j]);
            add(dp[i][j],presum);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
        ms(tmp,0);
    }
    cout<<dp[n][0]<<endl;
}
