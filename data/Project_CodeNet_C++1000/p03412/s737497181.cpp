#include<bits/stdc++.h>
using namespace std;
const int maxm=2e5+5;
int a[maxm];
int b[maxm];
int c[maxm];
int d[maxm];
int n;
int ask(int left,int right){//计算d数组中left<=x<right的x的数量
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
    if(!st||!ed)return 0;//如果不能同时满足x>=left且x<right,则无解
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