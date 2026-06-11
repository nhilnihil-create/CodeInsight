//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define int long long
#define ll long long
#define str string
#define db double
#define ac() cout<<"Yes"<<endl;
#define wa() cout<<"No"<<endl;
#define ddd cout<<"---debug---"<<endl;
#define ff(a,b) for(signed (a)=1;(a)<=(b);(a)++)
#define fff(a,b) for(signed (a)=0;(a)<(b);(a)++)
#define re readdd()
#define pr(a) printtt(a)
#define pee puts("");
#define eee putchar(' ');
#define pss(a) push_back(a)
#define ps(a) push(a)
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}//
int ppow(int a,int b,int mod){a%=mod;//
int ans=1;while(b){if(b&1)ans=ans*a%mod;
a=a*a%mod;b>>=1;}return ans;}
int readdd(){int x=0,f=1;char c=getchar();//
while(!isdigit(c)&&c!='-')c=getchar();
if(c=='-')f=-1,c=getchar();
while(isdigit(c))x=x*10+c-'0',c=getchar();
return f*x;}
void printtt(int x){if(x<0)putchar('-'),x=-x;
if(x>=10)printtt(x/10);putchar(x%10+'0');}
//
const int maxm=2e5+5;
int a[maxm];
int b[maxm];
int c[maxm];
int d[maxm];
int n;
int ask(int left,int right){//计算d数组中l<=x<r的x的数量
    int st=0,ed=0;
    int l=1,r=n;
    while(l<=r){//st尽量向左扩展
        int mid=(l+r)/2;
        if(d[mid]>=left){
            st=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    l=1,r=n;
    while(l<=r){//ed尽量向右扩展
        int mid=(l+r)/2;
        if(d[mid]<right){
            ed=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(!st||!ed)return 0;
    return ed-st+1;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int ans=0;
    for(int i=0;i<30;i++){
        int t=(1<<i);
        for(int j=1;j<=n;j++){
            c[j]=a[j]%(t*2);
            d[j]=b[j]%(t*2);
        }
        sort(c+1,c+1+n);
        sort(d+1,d+1+n);
        int cnt=0;
        for(int j=1;j<=n;j++){//枚举c
            cnt+=ask(t-c[j],t*2-c[j]);
            cnt+=ask(t*3-c[j],t*4-c[j]);
            cnt%=2;
        }
        if(cnt){
            ans+=(1<<i);
        }
    }
    cout<<ans<<endl;
    return 0;
}

