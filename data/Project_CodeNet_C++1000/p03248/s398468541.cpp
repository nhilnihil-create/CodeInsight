#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
vector<int>G[100005];
signed main(){
    string s;cin>>s;
    if(s[0]=='0'||s[s.size()-1]=='1')cout<<-1<<endl;
    else{
        rep(i,s.size()-1){
            if(s[i]!=s[s.size()-2-i]){
                cout<<-1<<endl;
                return 0;
            }
        }
        int nowpar=s.size()-1;
        for(int i=s.size()-2;i>=0;i--){
            G[nowpar].push_back(i);
            if(s[i]=='1')nowpar=i;
        }
        rep(i,s.size()){
            rep(j,G[i].size()){
                cout<<i+1<<' '<<G[i][j]+1<<endl;
            }
        }
    }
}