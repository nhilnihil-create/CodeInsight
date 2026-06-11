#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> a,int n){

    vector<int> dp(n+1);
    dp[1]=0;
    dp[2]=abs(a[1]-a[2]);
    for(int i=3;i<=n;i++)
    {
        int op1=abs(a[i]-a[i-1])+dp[i-1];
        int op2=abs(a[i]-a[i-2])+dp[i-2];
        dp[i]=min(op1,op2);
    }
    return dp[n];
}
 int main()
 {
 	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif


    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<solve(a,n)<<endl;


}
 	
 