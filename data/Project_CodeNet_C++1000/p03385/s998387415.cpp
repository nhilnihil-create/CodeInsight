#include<bits/stdc++.h>

using namespace std;

int main(){
    bool a=0,b=0,c=0;
    string s;
    cin>>s;
    for( int i=0;i<=2;i++){
        if(s[i]=='a')a=1;
        if(s[i]=='b')b=1;
        if(s[i]=='c')c=1;

    }
    if(a&&b&&c){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}
