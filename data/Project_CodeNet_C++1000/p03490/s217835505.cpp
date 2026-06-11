
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////

#define N 8001


int main(){
    string s;cin>>s;
    int len=s.size();
    vector<int>x,y;
    int f=1;
    int pos=0;
    while(pos<=len-1){
        int count=0;
        while(s[pos]=='F'&&pos<=len-1){pos++;count++;}
        if(f)x.push_back(count);
        else y.push_back(count);
        f=1-f;
        pos++;
    }
    int sizex=x.size(),sizey=y.size();
    bool dp[2][2*N];for(int i=0;i<=2*N-1;i++)dp[0][i]=dp[1][i]=false;
    dp[0][N+x[0]]=true;
    for(int i=1;i<sizex;i++){
        for(int j=0;j<=2*N-1;j++){
            if(j-x[i]>=0&&j+x[i]<=2*N-1)dp[i&1][j]=dp[(i+1)&1][j-x[i]]||dp[(i+1)&1][j+x[i]];
            else if(j-x[i]>=0)dp[i&1][j]=dp[(i+1)&1][j-x[i]];
            else if(j+x[i]<=2*N-1)dp[i&1][j]=dp[(i+1)&1][j+x[i]];
        }
    }
    int ansx;cin>>ansx;
    if(!dp[(sizex+1)%2][ansx+N]){
        cout<<"No"<<endl;
        return 0;
    }
    /*for(int i=0;i<=2*N-1;i++){
        if(dp[(sizex-1)%2][i])cout<<i-N<<" ";
    }cout<<endl;*/
    for(int i=0;i<=2*N-1;i++)dp[0][i]=dp[1][i]=false;
    dp[1][N]=true;
    for(int i=0;i<sizey;i++){
        for(int j=0;j<=2*N-1;j++){
            if(j-y[i]>=0&&j+y[i]<=2*N-1)dp[i&1][j]=dp[(i+1)&1][j-y[i]]||dp[(i+1)&1][j+y[i]];
            else if(j-y[i]>=0)dp[i&1][j]=dp[(i+1)&1][j-y[i]];
            else if(j+y[i]<=2*N-1)dp[i&1][j]=dp[(i+1)&1][j+y[i]];
        }
    }
    /*for(int i=0;i<=2*N-1;i++){
        if(dp[(sizey-1)%2][i])cout<<i-N<<" ";
    }cout<<endl;*/
    int ansy;cin>>ansy;
    if(!dp[(sizey+1)%2][ansy+N]){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}
