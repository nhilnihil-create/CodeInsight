#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
 }

ll lcm(ll a, ll b)  {
    return (a*b)/gcd(a, b);
}

ll fact(ll n){
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

string cal(string a,string b){

   ll a1=a.size(), b1=b.size();
   ll dp[a1+1][b1+1]={},i,j;

   for(i=1;i<=a1;i++){
        for(j=1;j<=b1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                //a[i-1] = ' ';
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
   }

   /*for(i=1;i<=a1;i++){
    for(j=0;j<=b1;j++)
        cout<<dp[i][j]<<" ";
    cout<<"\n";
   }*/
   string s;

   i = a1, j = b1;
   while(dp[i][j]!=0){
        //cout<<dp[i][j]<<" ";
        if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else{
            s = a[i-1] + s;
            i--;
            j--;
        }
   }
   //cout<<s<<"\n";
   return s;

}

void solve(){

    string a,b;
    cin>>a>>b;
    cout<<cal(a,b);

}

int main(){
    //freopen("D:\\codes\\1input.txt","r",stdin);
    //freopen("D:\\codes\\1output.txt","w",stdout);
    ll T=1;
    //cin>>T;
    for(ll t=1;t<=T;t++){

        //cout<<"Case #"<<t<<": ";
        solve();
        //cout<<"\n";
    }
}
