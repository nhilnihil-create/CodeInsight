#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(2,vector<int>(n));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int>result(n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp=v[i][j];
            int a=0,b=0;
            if(i>0)
            {
                a=v[i-1][j];
            }
            if(j>0)
            {
                b=v[i][j-1];
            }
            v[i][j]+=max(a,b);
        }
    }
    cout<<v[1][n-1];
}