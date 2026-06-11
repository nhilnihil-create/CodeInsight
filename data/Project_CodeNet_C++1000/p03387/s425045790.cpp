#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+10;
int a[8005];
int dp[8005][8005];
int sum[8005];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        swap(a,b);
    }
    if(a>c){
        swap(a,c);
    }
    if(b>c){
        swap(b,c);
    }
    int x=(c-b);
    int y=(c-(a+x));
    if(y%2){
        printf("%d\n",x+y/2+2);
    }
    else{
        printf("%d\n",x+y/2);
    }
    return 0;
}
