#include<iostream>
using namespace std;
int main(void){
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;
    bool yay(true);
    if(b-a>k)yay = false;
    if(c-a>k)yay = false;
    if(d-a>k)yay = false;
    if(e-a>k)yay = false;
    if(c-b>k)yay = false;
    if(d-b>k)yay = false;
    if(e-b>k)yay = false;
    if(d-c>k)yay = false;
    if(e-c>k)yay = false;
    if(c-d>k)yay = false;
    if(yay)cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
    return 0;
}