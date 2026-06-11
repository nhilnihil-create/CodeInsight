#include<iostream>
using namespace std;
int main()
{
    char s[5],a,b,c,d;
    cin>>s;
    if(s[0]=='+'){
        a=1;
    }
    else{
        a=-1;
    }
    if(s[1]=='+'){
        b=1;
    }
    else{
        b=-1;
    }
    if(s[2]=='+'){
        c=1;
    }
    else{
        c=-1;
    }
    if(s[3]=='+'){
        d=1;
    }
    else{
        d=-1;
    }
    cout<<a+b+c+d<<endl;
    return 0;

}
