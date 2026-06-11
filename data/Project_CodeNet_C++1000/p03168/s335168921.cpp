#include"bits/stdc++.h"
 

#define rep(i,a,n) for (int i = a; i <= n; i++)

#define ll long long int

//const int mod=1000000007;
using namespace std;
 
/*int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
*/

double   p[3100];
double dp[3100][3100];

int main()
{

    int a;
    cin>>a;
    
    for(int i=0;i<a;i++)
        cin>>p[i];
    
    dp[0][0]=1;
    
    for(int i=1;i<=a;i++)
    {
        for(int j=0;j<=i;j++)
        {
            
            if(j) dp[i][j]+=dp[i-1][j-1]*p[i-1];
            dp[i][j]+=dp[i-1][j]*(1-p[i-1]);
            
            
        }
        
    }
    double ret=0;
    
    for(int i=0;i<=a;i++)
    {
        if(i>a-i)
            ret+=dp[a][i];
        
    }

    cout<<setprecision(10);
    cout<<ret<<endl;
}
