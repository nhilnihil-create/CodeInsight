#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG
int main(){
    int n;
    cin>>n;
    string S;
    cin>>S;
    int E[n];
    int W[n];
    rep(i,n){
        int a=0;
        if(S[i]=='E') a=1;
        E[i]=a;
    }
    rep(i,n){
        int a=0;
        if(S[i]=='W') a=1;
        W[i]=a;
    }
//累積和作成
    int sumE[n+1];
    int sumW[n+1];
    sumE[0]=0;
    sumW[0]=0;

    rep1(i,n){
        sumE[i]=sumE[i-1]+E[i-1];
        sumW[i]=sumW[i-1]+W[i-1];
    }
    int ans=300000;
    rep(i,n){
        int sum;
        sum=(sumW[i]-sumW[0])+(sumE[n]-sumE[i+1]);
        ans=min(ans,sum);
    }

    cout<<ans<<endl;
}



