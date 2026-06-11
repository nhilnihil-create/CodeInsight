#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    n=2,m=3;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    bool no=false;
    for(int i=0;i<m;i++)
    {
            if(v[0][i]!=v[n-1][m-i-1])
        {
            no=true;
            break;
        }
    }
    if(no)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}