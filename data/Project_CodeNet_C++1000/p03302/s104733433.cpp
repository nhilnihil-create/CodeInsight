#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    int a,b;
    cin>>a>>b;
    if(a+b==15)cout<<'+'<<endl;
    else if(a*b==15)cout<<'*'<<endl;
    else cout<<'x'<<endl;
}

signed main(){
    //while(1)
    solve();
}