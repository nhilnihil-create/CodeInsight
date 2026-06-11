#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
   
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int wa=0;
    rep(i,n-1){
        wa+=a[i];

    }
    if(wa>a[n-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}