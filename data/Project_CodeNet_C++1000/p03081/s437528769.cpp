#include<bits/stdc++.h>
using namespace std;

int n,q;string s;
const int MAX=200000;
char d[MAX],t[MAX];
int judge(int k){
    int p=k;char m=s[k];
    for(int i=0;i<q;i++)
    {
        if(t[i]==m)
        {
            if(d[i]=='L')   
            p--;
            else    
            p++;
        }
        m=s[p];
        if(p<0)
        return -1;//left
        if(p>=n)
        return 1;//right

    }
    return 0;//otinai
}

int main(){
    cin>>n>>q;
    cin>>s;
    for(int i=0;i<q;i++)
    cin>>t[i]>>d[i];
    
    int l=0,r=s.size()-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(judge(mid)<=0)
        l=mid+1;
        else if(judge(mid)>0)
        r=mid-1;
    }
    int ans1;
    if(l>=n)
    ans1=n;
    else if(judge(l)==1)
    ans1=l;
    else if(judge(r)==1)
    ans1=r;
    l=0;r=s.size()-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(judge(mid)>=0)
        r=mid-1;
        else if(judge(mid)<0)
        l=mid+1;
    }
    int ans2;
    if(r<0)
    ans2=-1;
    else if(judge(r)==-1)
    ans2=r;
    else if(judge(l)==-1)
    ans2=l;
    
    cout<<ans1-ans2-1<<endl;
    return 0;
}