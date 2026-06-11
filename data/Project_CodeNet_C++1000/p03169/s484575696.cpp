// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "rewind"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;
int n;
double dp[301][301][301];
double cal(int c1,int c2,int c3){
    //cout<<c1<<" "<<c2<<" "<<c3<<endl;
    if (c1==0&&c2==0&&c3==0) return 0.0;
    if (dp[c1][c2][c3]!=0) return dp[c1][c2][c3];
    double ret = 1.0*n/(c1+c2+c3);

    if (c3>0) ret+= cal(c1,c2+1,c3-1)*c3/(c1+c2+c3);
    if (c2>0) ret+= cal(c1+1,c2-1,c3)*c2/(c1+c2+c3);
    if (c1>0) ret+= cal(c1-1,c2,c3)*c1/(c1+c2+c3);

    return dp[c1][c2][c3] = ret;

}
int cnt[4];
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    cin>>n;
    int tmp;

    for(int i=0;i<=300;i++)for(int j=0;j<=300;j++)for(int k=0;k<=300;k++) dp[i][j][k]=0;

    for(int i=0;i<n;i++) cin>>tmp,cnt[tmp]++;
    cout<<setprecision(12)<<fixed<<cal(cnt[1],cnt[2],cnt[3]);

}
