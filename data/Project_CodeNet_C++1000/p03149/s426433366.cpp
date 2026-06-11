#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    vector<int> a(4);
    for(auto& e:a)cin>>e;
    sort(a.begin(), a.end());
    if(a[0]==1&&a[1]==4&&a[2]==7&&a[3]==9){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    //while(1)
    solve();
}