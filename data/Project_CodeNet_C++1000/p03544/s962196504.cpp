#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long a[87];
    cin>>n;
    a[0]=2;a[1]=1;
    for (int i=2;i<=n;i++)a[i]=a[i-1]+a[i-2];
    cout<<a[n]<<endl;
}