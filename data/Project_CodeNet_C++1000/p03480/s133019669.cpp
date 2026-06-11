#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin>>s;
    int n=s.size();
    char ss=s[0];
    int ans=s.size();
    for(int i=1;i<s.size();i++){
        if(ss!=s[i]){
            int p=max(i,n-i);
            ans=min(ans,p);
            ss=s[i];
        }
    }
    cout<<ans<<endl;
}
