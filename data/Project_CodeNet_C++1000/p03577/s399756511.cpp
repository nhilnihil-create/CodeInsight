#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int n=s.size();
    string ans;
    rep(i,n){
        if(s.substr(i,8)=="LAVITSEF"){
            ans=s.substr(i+8);
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}