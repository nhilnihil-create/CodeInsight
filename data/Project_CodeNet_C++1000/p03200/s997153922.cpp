#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    long long ans=0,c=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='W'){
            ans+=i-c;
            c++;
        }
    }
    cout<<ans<<endl;
    return(0);
}