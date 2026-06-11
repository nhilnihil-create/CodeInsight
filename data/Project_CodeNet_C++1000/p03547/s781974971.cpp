#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    string t;
    cin>>s>>t;
    //int d=strcmp(s,t);
    if(s>t){cout<<">";}
    else if(s<t){cout<<"<";}
    else{cout<<"=";}
}