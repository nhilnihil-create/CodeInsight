#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int n,k;
    cin>>n>>k;
    long long ans=0;
    
    int i=n/k;//n以下のkの倍数の個数
    ans+=1*i;//a=b=c i
    if(i>=2) ans+=(long long)3*i*(i-1);//a=b!=c iP2
    if(i>=3) ans+=(long long)i*(i-1)*(i-2);//a!=b!=c!=a iP3
    
    //k%2!=0ではa%k=0,b%k=0,c%k=0のみ
    if(k%2==0){//a%2=k/2,b%2=k/2,c%2=k/2の場合
        int j=n/(k/2)-n/k;//n以下のk/2の倍数かつkの倍数でない個数
        ans+=1*j;//a=b=c j
        if(j>=2) ans+=(long long)3*j*(j-1);//a=b!=c jP2
        if(j>=3) ans+=(long long)j*(j-1)*(j-2);//a!=b!=c!=a jP3
    }
    
    printf("%lld\n",ans);
    return 0;
}