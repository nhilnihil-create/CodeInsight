#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long x[n],y[n];
    vector<pair<long long,long long>>p(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        p[i]={x[i],y[i]};
    }
    sort(x,x+n);
    sort(y,y+n);
    long long m=5000000000000000000;
    for(int l=0;l<n-1;l++){
        for(int r=l+1;r<n;r++){
            for(int d=0;d<n-1;d++){
                for(int u=d+1;u<n;u++){
                    int point=0;
                    for(int i=0;i<n;i++)if(x[l]<=p[i].first && p[i].first<=x[r] && y[d]<=p[i].second && p[i].second<=y[u])point++;
                    if(point>=k)m=min(m,(x[r]-x[l])*(y[u]-y[d]));
                }
            }
        }
    }
    cout<<m<<endl;
    return 0;
}