#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    bool greater=false;
    bool lower=false;
    for(int i=0;i<min((int)s.size(),(int)t.size());i++)
    {
        if(s[i]<t[t.size()-i-1])
        {
            lower=true;
            break;
        }
        if(s[i]>t[t.size()-i-1])
        {
            greater=true;
            break;
        }
    }
    if(greater){
        cout<<"No\n";
    }
    else
    if(lower){
        cout<<"Yes\n";
    }
    else
    {
        if(s.size()>=t.size()){
            cout<<"No\n";
        }
        else
        {
            cout<<"Yes\n";
        }
    }
}