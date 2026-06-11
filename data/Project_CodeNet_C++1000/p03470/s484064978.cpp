#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin>>n;
    int d[n+2];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    int sum=1;
    sort(d,d+n);
    for(int i=0;i<n-1;i++){
        if(d[i]!=d[i+1]){
            sum++;
        }
    }
    cout<<sum<<"\n";
    return(0);
}