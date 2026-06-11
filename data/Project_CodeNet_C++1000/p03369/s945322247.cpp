#include<bits/stdc++.h>

using namespace std;

int main(){
    int ans=700;
    string s;
    cin>>s;
    for( int i=0;i<=2;i++){
        if(s[i]=='o'){
            ans+=100;
        }
    }
    cout<<ans;
    return 0;
}


