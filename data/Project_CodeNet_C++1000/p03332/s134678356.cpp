#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=998244353;
int n,a,b,k;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
bool judge(int i){
    bool flag=false;
    int buf=k-a*i;
    if(buf>=0){
        //cout<<"K"<<endl;
        if(buf<=n*b){
            //cout<<"KK"<<endl;
            if((k-a*i)%b==0){
                flag=true;
                int num=(k-a*i)/b;
                if(num>n)flag=false;
                //cout<<"KKK"<<endl;
            }
        }
    }
    return flag;
}
int comv(vector<int> const& kaijo,int N,int kk){
    int res=kaijo[N];
    res*=modinv(kaijo[kk],MOD);
    res%=MOD;
    res*=modinv(kaijo[N-kk],MOD);
    res%=MOD;
    return res;
}
int solve(vector<int> const& kaijo,int i){
    int res=0;
    int r,bb;
    r=i;bb=(k-a*i)/b;
    if(bb<0)return 0;
    int buf=comv(kaijo,n,r);
    buf*=comv(kaijo,n,bb);
    buf%=MOD;res=buf;
    //printf("i=%lld, res=%lld\n",i,res);
    //printf("R=%lld, B=%lld\n",r,bb);
    return res;
}
signed main(){
    cin>>n>>a>>b>>k;
    int res=0;
    vector<int> kaijo(n+1,1);
    rep1(i,n){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=MOD;
    }
    rep(i,n+1){
        if(judge(i)){
            res+=solve(kaijo,i);
            res%=MOD;
            //cout<<i<<endl;
        }
    }
    cout<<res<<endl;
    return 0;
}