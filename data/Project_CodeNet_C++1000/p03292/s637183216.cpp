#include<bits/stdc++.h>
using namespace std;


int main(void){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,a+3);
    int dist[2];
    for(int i=0;i<2;i++){
        dist[i]=a[i+1]-a[i];
    }
    sort(dist,dist+2);
    int ans=0;
    for(int i=0;i<2;i++){
        ans+=dist[i];
    }
    cout<<ans<<endl;
    return 0;
}

