#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp map<int,int>
#define pp make_pair
#define endl "\n"
#define vi vector<int>
#define vbl vector<bool>
#define ll long long 
#define clock high_resolution_clock::now()

// auto duration = duration_cast<microseconds>(stop - start);  cout<<duration.count();

const int INF = 1e9+5;
const int mod = 1e9 + 7;

using namespace std;
using namespace std::chrono;

const int mx = 3005;

double dp[mx][mx];
double p[mx];

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)cin>>p[i];
    dp[0][0] = 1.0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j)dp[i][j]+=p[i-1]*dp[i-1][j-1];
            dp[i][j]+=(1-p[i-1])*(dp[i-1][j]);
            // cout<<dp[i][j]<<" ";
        }
    }
    double ans = 0;
    for(int i=0; i<=n; i++)if(i>n-i)ans+=dp[n][i];
    printf("%.12f\n", ans);
    
    
    

	return 0;
}
	
	
 