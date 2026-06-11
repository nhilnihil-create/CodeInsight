#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        if(mp.find(element)==mp.end())
        {
            mp[element]=1;
        }
        else
        {
            mp[element]++;
        }
    }
    int count=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->first<it->second){
            count+=it->second-it->first;
        }
        else
        if(it->first>it->second){
            count+=it->second;
        }
    }
    cout<<count;
}