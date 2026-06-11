#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string inp="";
    cin>>inp;
    if(inp.length()>9 && inp.length()<5){
        cout<<"NO\n";
    }
    else{
        int idx=0;
        if(inp[0]=='A' && inp[1]=='K' && inp[2]=='I' && inp[3]=='H'){
            idx=4;
        }
        else if(inp[0]=='K' && inp[1]=='I' && inp[2]=='H'){
            idx=3;
        }
        else{
            cout<<"NO\n";
            return 0;
        }
        if(inp[idx]=='A' && inp[idx+1]=='B' ){
            idx+=2;
        }
        else if(inp[idx]=='B'){
            idx++;
        }
        else{
            cout<<"NO\n";
            return 0;
        }
        if(inp[idx]=='A' && inp[idx+1]=='R' ){
            idx+=2;
        }
        else if(inp[idx]=='R'){
            idx++;
        }
        else{
            cout<<"NO\n";
            return 0;
        }
        if(inp.length()==idx){
            cout<<"YES\n";
            return 0;
        }
        else if(inp[idx]=='A'){
            idx++;
        }

        if(inp.length()==idx){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}