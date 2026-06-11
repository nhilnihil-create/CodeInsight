#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    if(n==1){
        cout<<(k==0?"0 0 1 1\n":"-1\n");
        return 0;
    }
    if(1<<n<=k){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<1<<n;i++)if(i!=k)cout<<i<<" ";
    cout<<k<<" ";
    for(int i=(1<<n)-1;i>=0;i--)if(i!=k)cout<<i<<" ";
    cout<<k<<endl;
}