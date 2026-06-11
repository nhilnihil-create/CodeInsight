#include<iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int index=-1;
    if(t.size()>s.size())
    {
        cout<<"UNRESTORABLE";
        return 0;
    }
    for(int i=0;i<=s.size()-t.size();i++)
    {
        bool no=false;
        for(int j=0;j<t.size();j++)
        {
            if(s[i+j]==t[j]||s[i+j]=='?')
            {
                continue;
            }
            else
            {
               
                no=true;
            }
        }
        if(!no){
            index=i;
        }
    }
    if(index!=-1)
    {
        for(int i=0;i<min(index,(int)s.size());i++)
        {
            if(s[i]=='?')
            {
                cout<<"a";
            }
            else{
                cout<<s[i];
            }
        }
        for(int i=0;i<t.size();i++)
        {
            cout<<t[i];
        }
        for(int i=t.size()+index;i<s.size();i++)
        {
            if(s[i]=='?')
            {
                cout<<"a";
            }
            else{
                cout<<s[i];
            }
            
        }
    }
    else
    {
        cout<<"UNRESTORABLE";
    }
}