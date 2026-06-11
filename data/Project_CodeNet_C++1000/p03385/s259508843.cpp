#include<iostream>
using namespace std;
int main(){
    bool tf=true;
    int tedad[3]={1,1,1};
    char str[4];
    cin>>str;
    for(int i=0;i<3;i++){
        if(str[i]=='a'){
            if(tedad[0]==1){
                tedad[0]=0;
            }
            else{
                tf=false;
                break;
            }
        }
        if(str[i]=='b'){
            if(tedad[1]==1){
                tedad[1]=0;
            }
            else{
                tf=false;
                break;
            }
        }
        if(str[i]=='c'){
            if(tedad[2]==1){
                tedad[2]=0;
            }
            else{
                tf=false;
                break;
            }
        }
    }
    if(tf==false){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
