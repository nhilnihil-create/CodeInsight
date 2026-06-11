#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
char s[N];
ll nm[N],nc[N],num[N];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='M'){
            nm[i]=nm[i-1]+1;
            nc[i]=nc[i-1];
            num[i]=num[i-1];
        }
        else if(s[i]=='C'){
            nm[i]=nm[i-1];
            nc[i]=nc[i-1]+1;
            num[i]=num[i-1]+nm[i];
        }
        else {
            nm[i]=nm[i-1];
            nc[i]=nc[i-1];
            num[i]=num[i-1];
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='D'){
                int ed=min(n,i+k-1);
                ans+=num[ed]-num[i]-nm[i]*(nc[ed]-nc[i]);
            }
        }
        printf("%lld\n",ans);
    }
}
