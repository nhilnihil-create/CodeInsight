#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    int oddcnt=0;
    vector<ll> even;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==1) oddcnt++;
        else even.push_back(a[i]);
    }

    if(oddcnt==n){
        cout<<0<<"\n";
        return 0;
    }
    int cnt=0;
    
    for(auto x : even){
        while(x%2==0){
            x/=2;
            cnt++;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}