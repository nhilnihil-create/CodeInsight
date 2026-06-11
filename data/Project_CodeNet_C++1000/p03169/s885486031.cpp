#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int n;

double dp[310][310][310];
double rec(int a, int b,int c){
    if(dp[a][b][c]>=0)return dp[a][b][c];
    if(a==0 && b==0 && c==0) return 0.0;

    double res=0.0;
    if(a>0)res+=rec(a-1,b,c)*a;
    if(b>0)res+=rec(a+1,b-1,c)*b;
    if(c>0)res+=rec(a,b+1,c-1)*c;

    res+=n;
    res*=1.0/(a+b+c);
    return dp[a][b][c]=res;
}


int main(){
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    int one=0,two=0,three=0;
    rep(i,n){
        if(a[i]==1)one+=1;
        if(a[i]==2)two+=1;
        if(a[i]==3)three+=1;
    }
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(10)<<rec(one,two,three)<<endl;
    
}