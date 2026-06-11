#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define all(v) v.begin(),v.end()
#define PB push_back
#define T(val) while(val--)
#define FIN for(i=0;i<n;i++)
#define FIS for(i=0;i<s.length();i++)
#define AIN for(i=0;i<n;i++){cin>>a[i];}
#define F(i,k,n) for(i=k;i<n;i++)
#define FG(i,k,n,x) for(i=k;i<n;i+=x)
#define YES cout<<"YES\n"; 
#define NO cout<<"NO\n"; 
#define ll long long
#define MOD 1000000007
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//sort(arr, arr+n, greater<int>()); For sorting in reverse order 
ll dp[105][100005],sum[105][100005]; 
// dp[x][y]
// dp[x][0]=1
// dp[1][0]=dp[1][1]=dp[1][2]=.....=dp[1][a[0]]=1;
// dp[x][y]=dp[x-1][y]+dp[x-1][y-1]+....dp[x-1][y-a[i]];
int solve(){
        int n;
        cin>>n;
        ll k,a[n];
        ll i,j;
        cin>>k;
        AIN
        ll x=0;
        for(i=1;i<=n;i++){
                for(j=0;j<=k;j++){
                        if(j==0){
                                dp[i][j]=1;
                                sum[i][j]=(dp[i][j]+MOD)%MOD;
                                continue;
                        }
                        if(i==1&&j<=a[0]){
                                dp[i][j]=1;
                                sum[i][j]=(sum[i][j-1]+dp[i][j]+MOD)%MOD;
                                continue;
                        }
                        if(i==1&&j>a[0]){
                                dp[i][j]=0;
                                sum[i][j]=(sum[i][j-1]+dp[i][j]+MOD)%MOD;
                                continue;
                        }
                        if(j>a[i-1]){
                                dp[i][j]=(sum[i-1][j]-sum[i-1][j-a[i-1]-1]+MOD)%MOD;
                                sum[i][j]=(sum[i][j-1]+dp[i][j]+MOD)%MOD;
                        }
                        else{
                                dp[i][j]=(sum[i-1][j]+MOD)%MOD;
                                sum[i][j]=(sum[i][j-1]+dp[i][j]+MOD)%MOD;                              
                        }
                }
        }
        /*
        for(i=1;i<=n;i++){
                for(j=0;j<=k;j++){
                cout<<dp[i][j]<<" ";
                }

                cout<<"\n";
        }*/
        cout<<dp[n][k]<<"\n";
  return 0;
}
int main(){
fast
        int t=1;
        // cin>>t; 
        T(t){
          solve();
        }
        return 0;
}