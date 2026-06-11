#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
    int x;
    cin>>x;
    long long int ans=0;
    if(x==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=35;i++){
        for(int j=2;j<20;j++){
            long long int now=pow(i,j);
            if(pow(i,j)<=x)ans=max(ans,now);

        }
    }
    cout<<ans<<endl;
}