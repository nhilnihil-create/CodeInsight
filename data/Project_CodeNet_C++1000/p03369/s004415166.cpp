#include<bits/stdc++.h>

using namespace std;

int main(){
    char s[3];
    int nedan=700;
    for(int i=0;i<3;i++){
        cin>>s[i];

        if(s[i]=='o'){
        nedan+=100;
        }
    }
    
    cout<<nedan<<endl;
}