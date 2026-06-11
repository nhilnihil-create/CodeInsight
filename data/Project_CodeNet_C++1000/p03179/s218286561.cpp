#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
//This is a O(n^2) implementation of the problem (Reference: Errichto's youtube video)
int main(){
    int n;
    string s;
    cin>>n>>s;
    int dp[n+1][n+1];
    int pref[n];
    //dp[i][j] means how many permutations exist with n=i and last 
    //number in the perumtation ending with j
    //The main trick in this question is that, just knowing
    //Which number do you want to place at the current position
    //and all the possible numbers you could have placed in 
    //the previous position, you can find out the number of
    //ways for the numbers in the current position using the 
    //previous ones. Okay..Okay.. I didn't mean to confuse you
    //...Let me tell this straight suppose, you know what are
    //the answers for first two positions, like in the case
    //of "3 <>", for position 1, you have 1 possibility
    //1<2 (1 possiblity for position 2), now comes the trick,
    //For position 3 1<2>1 (The question is can you place one at the end?)
    //Turns out yes, you can, if the previous position was 
    //3, but you know previous position cannot be 3 because you 
    //only had 2 spots, right? There is the catch, you add
    //the number of ways for which previous spot was 2 
    //and you can (imagine) change the above relation to 2<3<1
    //for all such possiblities, basically what I am saying is
    //for every number of ways you find after solving for some
    //i positions, you only care about the previous digit that
    //is possible and for all such ways you can guarantee that
    //you can get a permutation which ends in j.
    memset(dp,0,(n+1)*sizeof(dp[0]));
    dp[1][1] = 1;
    for(int i=2;i<=n;i++){
        memset(pref,0,4*n);
        for(int j=1;j<=(i-1);j++){
            pref[j] = (pref[j-1]+dp[i-1][j])%mod;
        }
        for(int j=1;j<=i;j++){
            int l,r;
            if(s[i-2]=='>')l=j,r=i-1;
            else l=1,r=j-1;
            if(l<=r)
                dp[i][j] = (dp[i][j]+pref[r]-pref[l-1]+mod)%mod;
        }
    }
    int ans = 0;
    for(int j=1;j<=n;j++){
        ans = (ans+dp[n][j])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}