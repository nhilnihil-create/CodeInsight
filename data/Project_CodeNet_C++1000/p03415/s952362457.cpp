#include<iostream>
using namespace std;
int main(){
    char str[3][4];
    for(int i=0;i<3;i++){
        cin>>str[i];
    }
    cout<<str[0][0]<<str[1][1]<<str[2][2];
}
