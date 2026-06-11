#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin>>s;
    int ans=1000000;
    rep(i,s.size()-2){
        int a=atoi((s.substr(i,3)).c_str());
        
        ans=min(ans,abs(753-a));

    }
    cout<<ans<<endl;

}