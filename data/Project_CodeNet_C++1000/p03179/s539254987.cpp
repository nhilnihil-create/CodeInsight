#include<bits/stdc++.h>
using namespace std;
#define mods 1000000007
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef long long int lint;
typedef unsigned long long int ulint;
list <lint> graph[100020];
lint hesap(lint a,bool b,lint ata);
lint n,k,dp[3020][3020];
char s[3020];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lint a,b,i,j,l,il;
    cin>>n;
    for(i=0;i<n-1;i++) cin>>s[i];
    dp[1][1]=1;
    for(i=2;i<=n;i++){
        lint pref=0;
        if(s[i-2]=='<'){
            for(j=1;j<=i;j++){
                dp[i][j]=pref;
                pref+=dp[i-1][j];
                pref%=mods;
                }
            
            }else{
                for(j=i;j>=1;j--){
                    pref+=dp[i-1][j];
                    pref%=mods;
                    dp[i][j]=pref;
                    }
            }
        }
        
    lint cev=0;
    for(i=1;i<=n;i++) cev+=dp[n][i], cev%=mods;
    //for(i=1;i<=n;i++){for(j=1;j<=n;j++) cout<<dp[i][j]<<" "; cout<<endl;}
    cout<<cev;
    
    }