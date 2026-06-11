#include<bits/stdc++.h>

using namespace std;
 
int main(){
    long long t,i,p=0;
    string s;
    cin>>s;
    t=s.size();
    for(i=0;i<t;i++){
        if(s[i]=='o')
        p++;
    }p=p+15-t;
    if(p>=8)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
    }
 
