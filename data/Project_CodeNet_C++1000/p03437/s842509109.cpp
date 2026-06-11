#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    ll x,y;
    cin>>x>>y;
    if(x%y==0){
        cout<<-1<<endl;
        return;
    }else{
        cout<<x<<endl;
    }   
}

signed main(){
    //while(1)
    solve();
}