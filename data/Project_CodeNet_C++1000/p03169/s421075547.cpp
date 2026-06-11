#include <bits/stdc++.h>

using namespace std;
double dp[301][301][301];
int n;
double solve(int a,int b,int c){
    if(a < 0 || b < 0 || c < 0)
    return 0;
    else if( a== 0 && (b==0 && c==0))
    return 0;
    if(dp[a][b][c] != -1)
    return dp[a][b][c];
    double res = n;
    if(a > 0)
    res += a*solve(a-1,b+1,c);
    if(b>0)
    res += b*solve(a,b-1,c+1);
    if(c>0)
    res += c*solve(a,b,c-1);
    res /= (a+b+c);
    dp[a][b][c] = res;
    return res;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int  i,j,k,one =0, two=0,three=0;
   for(i=0;i<=300;i++){
       for(j=0;j<=300;j++){
           for(k=0;k<=300;k++){
               dp[i][j][k]=-1;
           }
       }
   }
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==1)
        one ++;
        else if(arr[i]==2)
        two++;
        else
        three++;
    }
    
    cout << setprecision(10) << solve(three,two,one);;
     return 0;
}