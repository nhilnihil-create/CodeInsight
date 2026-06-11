#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    map<string,int> M;
    int null=0;
    M.insert(make_pair("aaaaaaaaaaa",0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        M.insert(make_pair(s,null));
        M[s]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        M.insert(make_pair(s,null));
        M[s]--;
    }
    int ans=-110;
    for(auto it=M.begin();it!=M.end();it++){
        ans=max(ans,it->second);
    }
    cout<<ans<<"\n";
    return(0);
}