#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int TIME = 200002;

int main(){
    int n,C;cin>>n>>C;
    int s[n],t[n],c[n];
    int tt[TIME]={0};
    int sm[TIME]={0};

    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i]>>c[i];
    }

    for(int i=1;i<=C;i++){
        for(int j=0;j<TIME;j++) {
            tt[j] = 0;
        }
        for(int j=0;j<n;j++) {
            if(c[j]==i) {
                tt[2*s[j]-1] = 1;
                tt[2*t[j]] = -1;
            }
        }
        for(int j=0;j<TIME-1;j++) {
            tt[j+1] += tt[j];
        }
        for(int j=0;j<TIME;j++) {
            if(tt[j]>0) sm[j]++;
        }
    }

    int ans=0;
    for(int i=0;i<TIME;i++) {
        if(ans<sm[i]) {
            ans=sm[i];
        }
    }
    cout<<ans<<endl;
}