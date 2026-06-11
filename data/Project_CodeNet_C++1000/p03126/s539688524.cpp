#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>ump;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int element;
            cin>>element;
            ump[element]++;
        }
    }
    int count=0;
    for(auto it=ump.begin();it!=ump.end();it++)
    {
        if(it->second==n){
            count++;
        }
    }
    cout<<count;
}