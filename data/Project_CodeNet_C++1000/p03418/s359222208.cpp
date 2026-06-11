#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    n++;
    long long x=0;
    for(long long i=k+1;i<n;i++){
        x+=n/i*(i-k);
        x+=max(n%i-k,0ll);
    }
    if(k==0)x=(n-1)*(n-1);
    cout<<x<<endl;
    return 0;
}
