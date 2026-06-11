#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,z,k;
    cin>>x>>y>>z>>k;
    long long a[x],b[y],c[z];
    for(int i=0;i<x;i++)cin>>a[i];
    for(int i=0;i<y;i++)cin>>b[i];
    for(int i=0;i<z;i++)cin>>c[i];
    vector<long long>ab;
    for(int i=0;i<min(x,k);i++){
        for(int j=0;j<min(y,k);j++){
            ab.push_back(a[i]+b[j]);
        }
    }
    sort(ab.begin(),ab.end(),greater<long long>());
    vector<long long>abc;
    long long s=ab.size();
    for(int i=0;i<min(s,k);i++){
        for(int j=0;j<min(z,k);j++){
            abc.push_back(ab[i]+c[j]);
        }
    }
    sort(abc.begin(),abc.end(),greater<long long>());
    for(int i=0;i<k;i++)cout<<abc[i]<<endl;
    return 0;
}