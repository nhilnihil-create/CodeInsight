#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int a,b;
    a=stoi(s.substr(0,2));
    b=stoi(s.substr(2,2));
    if(1<=a&&a<=12&&1<=b&&b<=12) cout<<"AMBIGUOUS"<<endl;
    else if(1<=a&&a<=12&&0<=b&&b<=99) cout<<"MMYY"<<endl;
    else if(0<=a&&a<=99&&1<=b&&b<=12) cout<<"YYMM"<<endl;
    else cout<<"NA"<<endl;
}