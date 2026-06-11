#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin>>n;
    int a[n];
    int pos=0,neg=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=a[i]-(i+1);
        if(a[i]>0)pos++;
        else if(a[i]<0)neg++;
        sum+=abs(a[i]);
    }
    sort(a,a+n);
    //i thought almost correct
    int mid=a[n/2];
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(mid-a[i]);
    }
    cout<<ans;
}

