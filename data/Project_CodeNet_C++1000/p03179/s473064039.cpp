
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long
#define ld long double
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int power_mod(int num,int g)
{
    if(g==0)return 1;
    if(g%2==1)return (num*power_mod((num*num)%mod,g/2))%mod;
    return power_mod((num*num)%mod,g/2);
}
int power(int num,int g)
{
    if(g==0)return 1;
    if(g%2==1)return (num*power((num*num),g/2));
    return power((num*num),g/2);
}
int n;
string s;
int a[3005][3005];
int32_t main()
{
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>n>>s;
    a[0][1]=a[0][2]=0;
    if(s[0]=='<')a[0][2]=1;
    else a[0][1]=a[0][2]=1;
    a[0][0]=0;
    a[0][3]=a[0][2];
    for(int i=1;i<n-1;i++) {
        for(int j=0;j<=i+3;j++) {
            
            if(j==0) {
                a[i][j]=0;
            }
            else if(j==i+3)a[i][j]=a[i][j-1];
            else {
                if(s[i]=='<') {
                    a[i][j]=a[i][j-1]+a[i-1][j-1];
                    a[i][j]%=mod;
                }
                else {
                    a[i][j]=a[i][j-1]+(a[i-1][i+1]-a[i-1][j-1]+mod);
                    // cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
                    a[i][j]%=mod;
                }
            }
            // cout<<a[i][j]<<" ";
        }
        // cout<<endl;
    }
    int ans=0;
    cout<<a[n-2][n]<<endl;
    return 0;
}
