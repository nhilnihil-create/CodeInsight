#include <bits/stdc++.h>
#define lol long long
#define vec vector
using namespace std;
int main(){
    int n,m,ans=0;
    string s;
    cin>>n>>m>>s;
    for(int i=0;i<=n+m;i++){
        if(i<n){
            if(s[i]=='-'){
                ans=1;
                break;
            }
        }
        else if(i==n){
            if(s[i]!='-'){
                ans=1;
                break;
            }
        }
        else{
            if(i==n+m){
                if(s[i+1]>='0' && s[i+1]<='9' || s[i+1]=='-'){
                    ans=1;
                    break;
                }
            }
            if(s[i]=='-'){
                ans=1;
                break;
            }
        }
    }
    if(ans==1) cout<<"No\n";
    else cout<<"Yes\n";
    return(0);
}