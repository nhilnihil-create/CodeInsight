#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200001],ans,L;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=0;
    if(a[0]!=0){cout<<-1<<endl;return 0;}
    reverse(a,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i-1]>a[i]+1){cout<<-1<<endl;return 0;}
        else if(a[i-1]!=a[i]+1)ans+=a[i];
    }
    cout<<ans<<endl;
}
