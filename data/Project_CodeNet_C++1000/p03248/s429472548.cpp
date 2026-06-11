// ARC_103
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

string s;

int main(){
    cin>>s;
    int n=s.size();
    if(s[0]=='0'||s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }

    rep(i,n-2)if(s[i]!=s[n-2-i]){
        cout<<-1<<endl;
        return 0;
    }

    int par=n;
    for(int i=n-2;i>=0;i--){
        cout<<i+1<<" "<<par<<endl;
        if(s[i]=='1')par=i+1;
    }
}