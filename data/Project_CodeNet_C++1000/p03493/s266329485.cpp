#include<iostream>
using namespace std;
int main(){
    int tedad=0;
    char str[4];
    cin>>str;
    for(int i=0;i<3;i++){
        if(str[i]=='1'){
            tedad++;
        }
    }
    cout<<tedad;
}
