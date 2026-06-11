#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    string s;
    cin>>s;
    int cnt=0;
    for(auto e:s){
        if(e=='2')cnt+=1;
    }
    cout<<cnt<<endl;
}

signed main(){
    //while(1)
    solve();
}