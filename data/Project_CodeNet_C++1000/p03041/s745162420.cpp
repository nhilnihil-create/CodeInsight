#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
#define ll long long
#define ar array

int n,k;
char c[50];

void solve(){
    cin>>n>>k;
    rep(i,n){
        cin>>c[i];
        if(i==k-1){
            c[i]=c[i]+('a'-'A');
        }
        cout<<c[i];
    }
}

int main(){
    solve();
    cout<<endl;
    return 0;
}