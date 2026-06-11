#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<char>>v(3,vector<char>(3));
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cin>>v[i][j];
        }
    }
    string s="";
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(i==j)
            {
                s+=v[i][j];
            }
        }
    }
    cout<<s;
}