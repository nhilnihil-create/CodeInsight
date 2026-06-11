#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define nl printf("\n")
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
using namespace std;
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int al=a.length();
    int bl=b.length();
    int dp[al+1][bl+1];
    for(int i=0;i<=al;i++) dp[i][0]=0;
    for(int i=0;i<=bl;i++) dp[0][i]=0;

    for(int i=1;i<=al;i++){
        for(int j=1;j<=bl;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    string s;
    int i=al;
    int j=bl;
    while(i>0&&j>0){
        if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]==dp[i][j-1]) j--;
        else if(dp[i][j]==dp[i-1][j-1]){
            i--; j--;
        }
        else{
            s.pb(a[i-1]);
            i--; j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;
    nl;
}
