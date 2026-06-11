// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "Sushi"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;
double dp[301][301][301];
int n;
double cal(int i,int j,int k){
    if(i+j+k==0) return 0;
    //cout<<i<<" "<<j<<" "<<k<<" "<<endl;

    if ((int)dp[i][j][k] != -1) return dp[i][j][k];

    double val =  1.0*n/(i+j+k) ;

    if (i>0) val+= 1.0*i/(i+j+k)*cal(i-1,j,k);
    if (j>0) val+= 1.0*j/(i+j+k)*cal(i+1,j-1,k);
    if (k>0) val+= 1.0*k/(i+j+k)*cal(i,j+1,k-1);
    return dp[i][j][k] = val;
}
int cnt[4];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        cnt[tmp]++;
    }

    for(int i =0;i<301;i++)
        for(int j =0;j<301;j++)
            for(int k =0;k<301;k++) dp[i][j][k] =-1;

    cout<<setprecision(15)<<fixed<<cal( cnt[1],cnt[2], cnt[3] );


}
