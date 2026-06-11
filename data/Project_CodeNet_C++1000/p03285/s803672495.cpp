#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
bool flg=false;
for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
        if(i*4+j*7==n){
        flg=true;
        break;
    }}
}
if(flg){cout<<"Yes";}
else {cout<<"No";}}
