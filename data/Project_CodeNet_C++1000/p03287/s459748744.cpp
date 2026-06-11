#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,n;
    cin>>n>>m;
    vector<long long> v(n+1);
    v[0]=0;
    for(int i=0;i<n;i++){
        cin>>v[i+1];
    }
    for(int i=0;i<n;i++){
        v[i+1]+=v[i];
    }
    for(int i=0;i<=n;i++){
        v[i]=v[i]%m;
    }
    sort(v.begin(),v.end());
    long long s=0;
    long long t=1;
    v.push_back(-1);
    for(int i=0;i<=n;i++){
        if (v[i+1]==v[i]) t++;
        else{
            s+=(t-1)*t/2;
            t=1;
        }
    }
    cout<<s;
}