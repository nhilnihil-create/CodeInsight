#include<iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    bool no=false;
    if(s[s.size()-1]!=t[0]){
        no=true;
    }
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        no=false;
        for(int j=0;j<n;j++)
        {
            if(s[(j+i)%(s.size())]!=t[j]){
                no=true;
                break;
            }
            else
            {
            }
        }
        if(!no){
            break;
        }
    }
    if(no){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
}