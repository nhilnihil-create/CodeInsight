#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int maxv=0;
    int sum=0;
    rep(i,5){
        int t;
        cin>>t;
        int x=t%10;
        if(x!=0){
            t+=(10-x);
            maxv=max(maxv,10-x);
        }
        sum+=t;
    }
    cout<<sum-maxv<<"\n";
    return 0;
}