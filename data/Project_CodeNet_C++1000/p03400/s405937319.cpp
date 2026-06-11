#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,d,x,ans=0;
    cin>>n;
    cin>>d>>x;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+=(d-1)/a[i]+1;
    }
    cout<<ans+x<<endl;
    return 0;
}
