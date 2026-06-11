#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    long long m=1000000000000000;
    for(int i=0;i+k<=n;i++){
        m=min(m,min(abs(x[i]),abs(x[i+k-1]))+x[i+k-1]-x[i]);
    }
    cout<<m<<endl;
    return 0;
}