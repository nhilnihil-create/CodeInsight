#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int ichi=0;
    int ni=0;
    int san=0;
    int yon=0;
    for(int i=0;i<3;i++){
        int a,b;
        cin>>a>>b;
        if(a==1||b==1){
            ichi++;
        }
        if(a==2||b==2){
            ni++;
        }
        if(a==3||b==3){
            san++;
        }
        if(a==4||b==4){
            yon++;
        }
    }
    if(max({ichi,ni,san,yon})==2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}