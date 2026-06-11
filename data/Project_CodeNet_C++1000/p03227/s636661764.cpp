#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    string s;
    cin>>s;
    if(s.size()==2)cout<<s<<endl;
    else{
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
}

signed main(){
    //while(1)
    solve();
}