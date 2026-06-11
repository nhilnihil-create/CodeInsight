#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    vector<int>v1(26,0),v2(26,0);
    for(int i=0;i<s.size();i++)
    {
        v1[s[i]-'a']++;
    }
    unordered_map<int,int>ump1,ump2;
    for(int i=0;i<t.size();i++)
    {
        v2[t[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        ump1[v1[i]]++;
    }
    for(int i=0;i<26;i++)
    {
        ump2[v2[i]]++;
    }
    bool no=false;
    for(auto it=ump1.begin();it!=ump1.end();it++){
        if(ump2[it->first]!=it->second){
            no=true;
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