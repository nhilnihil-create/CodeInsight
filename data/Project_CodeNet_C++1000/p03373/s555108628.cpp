#include <bits/stdc++.h>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    long long ans=1000000000;
    for(int i=0;i<200001;i++){
        long long pay=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
        ans=min(ans,pay);
    }
    cout<<ans<<endl;
}