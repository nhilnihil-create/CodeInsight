#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

ll dp[2100][2];

int main(){
    int N;
    ll Z,W,a[2100];
    cin>>N>>Z>>W;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=N-1;i>=1;i--){
        for(int j=0;j<=1;j++){
            if(j==0){
                ll temp=0;
                int k=i+1;
                while(k<=N-1){
                    temp=max(temp,dp[k][1]);
                    k++;
                }
                temp=max(temp,abs(a[N-1]-a[i-1]));
                dp[i][0]=temp;
            }else{
                ll temp=1100000000;
                int k=i+1;
                while(k<=N-1){
                    temp=min(temp,dp[k][0]);
                    k++;
                }
                temp=min(temp, abs(a[N-1]-a[i-1]) );
                dp[i][1]=temp;
            }
            if(j==1) ans=max(ans,dp[i][j]);
        }
    }
    
    ans=max(abs(a[N-1] - W) ,ans );
    cout<<ans<<endl;
}

