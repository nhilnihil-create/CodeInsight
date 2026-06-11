#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int a=0;
    long long ans=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='A'){
            if(s[i+1]=='C')a=0;
            else a++;
        }
        if(s[i]=='B'){
            if(s[i+1]=='C')ans+=a;
            else a=0;
        }
        if(s[i]=='C' && s[i+1]=='C')a=0;
    }
    cout<<ans<<endl;
    return 0;
}