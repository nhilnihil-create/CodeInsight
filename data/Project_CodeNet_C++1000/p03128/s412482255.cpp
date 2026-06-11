#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    rep(i,m)cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<int>nd(10);
    vector<int>dp(n+1,-1);
    
    vector<int>cnt(n+1);
    dp[0]=0;
   
    nd[1]=2;
    nd[2]=5;
    nd[3]=5;
    nd[4]=4;
    nd[5]=5;
    nd[6]=6;
    nd[7]=3;
    nd[8]=7;
    nd[9]=6;

    rep(i,n+1){
        rep(j,m){
            if(i>=nd[a[j]]&&dp[i-nd[a[j]]]>=0){
                
                dp[i]=max(dp[i],dp[i-nd[a[j]]]+1);
            }
        }
    }
    int num=dp[n];
    while(num>0){
        rep(j,m){
            if(n>=nd[a[j]]&&dp[n-nd[a[j]]]+1==dp[n]){
                cout<<a[j];
                num--;
                n-=nd[a[j]];
                break;
            }
        }
    }


    cout<<endl;
    return 0;
}