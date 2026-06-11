#include<iostream>
using namespace std;
int main(){
    int a,b;
    string s;
    cin>>a>>b>>s;
    bool no=false;
    for(int i=0;i<a;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            continue;
        }
        no=true;
    }
    if(s[a]!='-')
    no=true;
    for(int i=a+1;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            continue;
        }
        no=true;
    }
    if(no)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
}