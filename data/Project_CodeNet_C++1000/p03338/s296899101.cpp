#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin>>n>>s;
    set<char>syu;
    int ans=0;
    rep(i,n){
        syu.clear();
        for(int j=0;j<=i;j++){
            for(int k=i+1;k<n;k++){
                if(s[j]==s[k])syu.insert(s[j]);
            }


        }
        int sisi=syu.size();
        ans=max(ans,sisi);
    }
    cout<<ans<<endl;


}