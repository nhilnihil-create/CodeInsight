#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,m;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>m;
    string t[m];
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    int ans=0;
    int tmp=0;
    for(int i =0;i<n;i++){
        tmp=count(s,s+n,s[i])-count(t,t+m,s[i]);
        ans=max(ans,tmp);
    }
    
    cout<<ans;
}
