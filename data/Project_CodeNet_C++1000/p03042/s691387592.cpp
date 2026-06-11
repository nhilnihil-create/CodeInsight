#include <iostream>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int a=(s[0]-'0')*10+s[1]-'0';
    int b=(s[2]-'0')*10+s[3]-'0';
    bool yymm=false;
    bool mmyy=false;
    if(a<=12&&a!=0) mmyy=true;
    if(b<=12&&b!=0) yymm=true;
    if(mmyy&&yymm){
        cout<<"AMBIGUOUS"<<endl;
    }else if(mmyy){
        cout<<"MMYY"<<endl;
    }else if(yymm){
        cout<<"YYMM"<<endl;
    }else{
        cout<<"NA"<<endl;
    }
}
