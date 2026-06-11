#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,ll> lucas;

    lucas[1]=1;
    lucas[2]=3;

    for(int i=3;i<=n;i++){
        lucas[i]=lucas[i-1]+lucas[i-2];
    }
    cout<<lucas[n]<<"\n";
    return 0;    
}