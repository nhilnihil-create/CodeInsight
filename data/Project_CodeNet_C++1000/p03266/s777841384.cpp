#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    int n,k;
    cin>>n>>k;
    long long s=0;
    for(int i=1;i<=n;i++) a[i % k]++;
    s = a[0] * a[0] * a[0];
    if(k % 2 == 0) s += a[k >> 1 ] * a[k >> 1] * a[k >> 1];
    cout<<s;
    return 0;
}