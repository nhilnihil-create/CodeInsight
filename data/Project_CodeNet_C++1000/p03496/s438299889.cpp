#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int main()
{
    cin>>n;int mi=1e7,pmi,mx=-1e7,pmx;
    for(int i=1;i<=n;i++)cin>>arr[i],mi=min(mi,arr[i]),mx=max(mx,arr[i]);
    for(int i=1;i<=n;i++) {
        if(arr[i]==mi)pmi=i;
        if(arr[i]==mx)pmx=i;
    }
    if(mi>=0) {//都大于等于0
        cout<<n-1<<endl;
        for(int i=1;i<n;i++)cout<<i<<" "<<i+1<<endl;
    } else if(mx<=0) {//都小于等于
        cout<<n-1<<endl;
        for(int i=n;i>1;i--)cout<<i<<" "<<i-1<<endl;
    } else {//有正有负
        cout<<2*n-1<<endl;
        if(abs(mi)>abs(mx)) {//转化为第二种
            for(int i=1;i<=n;i++)cout<<pmi<<" "<<i<<endl;
            for(int i=n;i>1;i--)cout<<i<<" "<<i-1<<endl;
        } else {//转化为第一种
            for(int i=1;i<=n;i++)cout<<pmx<<" "<<i<<endl;
            for(int i=1;i<n;i++)cout<<i<<" "<<i+1<<endl;
        }
    }
}
