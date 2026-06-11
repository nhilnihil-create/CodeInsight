#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int even=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==0) even++;
    }
    int p=1;
    rep(i,n){
        p*=3;
    }
    if(even==0) cout<<p-1<<"\n";
    else cout<<p-pow(2,even)<<"\n";
    return 0;
}